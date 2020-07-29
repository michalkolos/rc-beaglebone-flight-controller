//
// Created by kolos on 7/27/20.
//

#include "ServoController.h"

ServoController::ServoController(bool startWorker, CraftState &craftState) :
    WorkerThread(startWorker), craftState(craftState) {}
