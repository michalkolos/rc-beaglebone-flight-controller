//
// Created by kolos on 7/30/20.
//

#include "SimpleDirector.h"
#include "../utils/Utils.h"
#include "DIRECTOR_SETTINGS.h"


SimpleDirector::SimpleDirector(CraftState &craftState, bool startWorker)
        : GenericDirector(craftState, "SIMPLE_DIRECTOR", startWorker) {}

void SimpleDirector::task() {

    //  Set throttle:
    setServoFromSbus(DIRECTOR_SETTINGS::THROTTLE_SERVO, DIRECTOR_SETTINGS::THROTTLE_SBUS);

    //  Set elevator:
    setServoFromSbus(DIRECTOR_SETTINGS::ELEVATOR_SERVO, DIRECTOR_SETTINGS::ELEVATOR_SBUS, true);

    //  Set ailerons:
    setServoFromSbus(DIRECTOR_SETTINGS::AILERON_LEFT_SERVO, DIRECTOR_SETTINGS::AILERON_SBUS, true);
    setServoFromSbus(DIRECTOR_SETTINGS::AILERON_RIGHT_SERVO, DIRECTOR_SETTINGS::AILERON_SBUS);

    Utils::sleep_ms(20);
}

float SimpleDirector::sbusToServo(uint16_t sbusVal, uint16_t maxSbus, bool reversed) {
    float servoVal = (float)sbusVal / (float)maxSbus;

    if(reversed){
        servoVal = 1 - servoVal;
    }

    return servoVal;
}
