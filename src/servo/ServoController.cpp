//
// Created by kolos on 7/27/20.
//

//#include <robotcontrol.h>
#include <iostream>
#include <unistd.h>
#include <rc/servo.h>
#include <rc/time.h>
#include "ServoController.h"

//  TODO: Handle possible exceptions thrown by the robot library.

ServoController::ServoController(CraftState &craftState, int channelNo,
                                 int pulseFreq, int  minPosUs, int maxPosUs) :
    WorkerThread(true) {

    servoData = new ServoData(channelNo, pulseFreq);
    craftState.registerData(servoData);

    if(minPosUs >= 0 && maxPosUs >=0){
        servoData->setRange(minPosUs, maxPosUs);
    }
    rc_servo_cleanup();

    rc_servo_init();
    if(rc_servo_power_rail_en(1) == -1){
        std::cerr << "Unable to start servo power rail" << std::endl;
    }else{
        rc_servo_set_esc_range(servoData->getMinPosUs(), servoData->getMaxPosUs());
//        rc_servo_set_esc_range(800, 2200);
        servoData->setInterfaceRunning(true);
    }

}



void ServoController::task() {
    if(servoData->isInterfaceRunning()){

        servoData->takeResource();
        std::array<float, ServoData::MAX_CHANNELS_NO>& channels = servoData->getChannels();
        for(int i = 0; i < servoData->getChannelsNo(); i++){
            rc_servo_send_esc_pulse_normalized(i + 1, channels[i]);
        }
        servoData->releaseResource();

        rc_usleep(1000000/servoData->getPulseFreq());
    }
}

void ServoController::cleanup() {
    rc_servo_cleanup ();
}
