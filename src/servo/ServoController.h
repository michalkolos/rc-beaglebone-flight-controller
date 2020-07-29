//
// Created by kolos on 7/27/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVOCONTROLLER_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVOCONTROLLER_H


#include "../worker/WorkerThread.h"
#include "../data/CraftState.h"

class ServoController : public WorkerThread{
private:
    CraftState& craftState;
public:
    ServoController(bool startWorker, CraftState &craftState);

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVOCONTROLLER_H
