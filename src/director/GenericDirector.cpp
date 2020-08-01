//
// Created by kolos on 7/30/20.
//

#include "GenericDirector.h"
#include "../utils/Utils.h"

#include <utility>
#include <iostream>


GenericDirector::GenericDirector(CraftState &craftState, std::string directorTag, bool startWorker)
    : directorTag(std::move(directorTag)), WorkerThread(startWorker){

    servoData = (ServoData*)loadData(craftState, "SERVO");
    sbusData = (SbusData*)loadData(craftState, "SBUS");

}

GenericData* GenericDirector::loadData(CraftState &craftState, const std::string& tag) {

    GenericData* loadedData;
    do{
        loadedData = craftState.getDataByTag(tag);
        if(loadedData == nullptr || loadedData->getTag() != tag){
            std::cerr << directorTag << " // Waiting for data: " << tag << std::endl;
            Utils::sleep_ms(100);
        }
    }while(loadedData == nullptr || loadedData->getTag() != tag);

    return loadedData;
}

void GenericDirector::setServoFromSbus(int servo, int sbus, bool reverse, float lowRate, float highRate) {
    float servoVal = (float)sbusData->getChannels()[sbus] / (float)sbusData->MAX_CH_VAL;

    if(reverse){ servoVal = 1.0 - servoVal; }

    if(lowRate < 1.0 || highRate < 1.0) {
        if (servoVal < 0.5) {
            servoVal += (0.5 + servoVal) * lowRate;
        }else if( servoVal > 0.5){
            servoVal -= (servoVal - 0.5) * lowRate;
        }
    }

    if(servoVal > 1.0){ servoVal = 1.0; }
    if(servoVal < 0.0){ servoVal = 0.0; }

    servoData->setChannel(servo, servoVal);
}

