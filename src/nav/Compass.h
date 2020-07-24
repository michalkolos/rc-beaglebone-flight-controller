//
// Created by kolos on 19.07.2020.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_COMPASS_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_COMPASS_H

#include <iostream>
#include <fstream>


#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include "../data/CraftState.h"


class Compass {
private:
    int fileDescriptor;

public:
    Compass(const std::string& deviceFileName, int i2cAddress);

    

    CompassData measure();
    void test();

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_COMPASS_H
