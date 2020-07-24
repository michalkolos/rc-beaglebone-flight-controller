//
// Created by kolos on 7/20/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_GPSSERIALCONNECTION_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_GPSSERIALCONNECTION_H


#include <iostream>
#include "../../interfaces/SerialConnection.h"
#include "../../data/GpsData.h"
#include "NmeaParser.h"

class GpsSerialConnection : public SerialConnection{

public:

    GpsSerialConnection(const std::string& interfaceFilePath,
                     int baudRate,
                     int parityBit = 0,
                     int stopBits = 0,
                     int hardwareFlowControl = 0,
                     int bitsPerByte = 8);

    void read(GpsData& gpsData);
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_GPSSERIALCONNECTION_H
