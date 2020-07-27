//
// Created by kolos on 7/27/20.
//

#include <ctime>

#include "Utils.h"

void Utils::sleep_ms(int milliseconds){

    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, nullptr);
}
