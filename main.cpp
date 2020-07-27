#include <iostream>
#include "src/nav/Compass.h"
#include "src/nav/gps/NmeaParser.h"
//#define PORTNAME "/dev/ttyO1"
#include <ctime>
#include "src/nav/gps/GpsSerialConnection.h"
#include "src/interfaces/SerialConnection.h"
#include "src/nav/sbus/SbusSerialConnection.h"
#include "src/utils/Utils.h"


const std::string COMPASS_DEVICE_FILE = "/dev/i2c-1";
const int COMPASS_I2C_ADDRESS = 0x1E;

int main() {
    std::cout << "Hello, World!" << std::endl;

//    Compass compass(COMPASS_DEVICE_FILE, COMPASS_I2C_ADDRESS);
//    Serial serial("/dev/ttyO2", B115200);

//    SerialConnection serialConnection("/dev/ttyO2", B115200);
//    SerialData serialData;

    CraftState craftState;
//    GpsSerialConnection gpsSerialConnection(craftState,
//            "/dev/ttyO1", 115200, true);

    SbusSerialConnection sbusSerialConnection(craftState,
            "/dev/ttyO2", true);

//    sbusSerialConnection.debug();

//    GpsData gpsData;

//    NmeaParser nmeaParser;

    while(true){

        std::cout << craftState.getSbusData().toString() << std::endl;
        Utils::sleep_ms(100);


//        gpsSerialConnection.read();
//        GpsData gpsData = craftState.getGpsData();
//
//        std::cout << gpsData.toString() << std::endl;
//
//        sleep(1);

//        serialConnection.read(serialData);
//        std::cout << serialData.toString() << std::endl;

//        CompassData compassData = compass.measure();
//        std::cout << compassData.toString() << std::endl;

//        nmeaParser.parseLine(serial.readLine());

//        std::cout << serial.readLine();
//
//        std::vector<int> magneticVector = compass.measure();
//
//        std::cout << "Magnetic field in X-Axis : " << magneticVector[0] << std::endl;
//        std::cout << "Magnetic field in Y-Axis : " << magneticVector[1] << std::endl;
//        std::cout << "Magnetic field in Z-Axis : " << magneticVector[2] << std::endl;
    }





    return 0;
}

