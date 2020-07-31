//
// Created by kolos on 7/27/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVOCONTROLLER_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVOCONTROLLER_H


#include "../worker/WorkerThread.h"
#include "../data/CraftState.h"
#include "../data/ServoData.h"

class ServoController : public WorkerThread{
private:
    ServoData* servoData;
    void task() override;
    void cleanup() override;
public:
    explicit ServoController(CraftState &craftState,
         int channelNo = 8,
         int pulseFreq = 50,
         int minPosUs = -1,
         int maxPosUs = -1);

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVOCONTROLLER_H
