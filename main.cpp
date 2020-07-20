#include <iostream>
#include "src/nav/Compass.h"

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>


const std::string COMPASS_DEVICE_FILE = "/dev/i2c-1";
const int COMPASS_I2C_ADDRESS = 0x1E;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Compass compass(COMPASS_DEVICE_FILE, COMPASS_I2C_ADDRESS);
    while(true){
        std::vector<int> magneticVector = compass.measure();

        std::cout << "Magnetic field in X-Axis : " << magneticVector[0] << std::endl;
        std::cout << "Magnetic field in Y-Axis : " << magneticVector[1] << std::endl;
        std::cout << "Magnetic field in Z-Axis : " << magneticVector[2] << std::endl;
    }





    return 0;
}
