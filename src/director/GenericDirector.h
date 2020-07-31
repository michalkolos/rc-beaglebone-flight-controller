//
// Created by kolos on 7/30/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDIRECTOR_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDIRECTOR_H


#include "../worker/WorkerThread.h"
#include "../data/CraftState.h"
#include "../data/ServoData.h"

class GenericDirector : public WorkerThread{
private:
    std::string directorTag = "NO_DIRECTOR_TAG";

protected:

    ServoData* servoData;
    SbusData* sbusData;

    GenericDirector(CraftState &craftState, std::string directorTag, bool startWorker = true);
    GenericData* loadData(CraftState &craftState, const std::string& tag);
    void task() override = 0;
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDIRECTOR_H
