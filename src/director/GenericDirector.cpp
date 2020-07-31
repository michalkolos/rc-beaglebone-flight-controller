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

