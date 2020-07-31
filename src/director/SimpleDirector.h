//
// Created by kolos on 7/30/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SIMPLEDIRECTOR_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SIMPLEDIRECTOR_H


#include "GenericDirector.h"

class SimpleDirector : public GenericDirector{
private:
    void task() override;
    static float sbusToServo(uint16_t sbusVal, uint16_t maxSbus, bool reversed = false);
public:
    SimpleDirector(CraftState &craftState, bool startWorker = true);


};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SIMPLEDIRECTOR_H
