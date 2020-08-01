//
// Created by kolos on 7/30/20.
//

#include "SimpleDirector.h"
#include "../utils/Utils.h"

SimpleDirector::SimpleDirector(CraftState &craftState, bool startWorker)
        : GenericDirector(craftState, "SIMPLE_DIRECTOR", startWorker) {}

void SimpleDirector::task() {


    float servoVal = sbusToServo(sbusData->getChannels()[2], sbusData->MAX_CH_VAL);
    servoData->setChannel(0, servoVal);
    Utils::sleep_ms(20);
}

float SimpleDirector::sbusToServo(uint16_t sbusVal, uint16_t maxSbus, bool reversed) {
    float servoVal = (float)sbusVal / (float)maxSbus;

    if(reversed){
        servoVal = 1 - servoVal;
    }

    return servoVal;
}
