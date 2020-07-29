//
// Created by kolos on 7/21/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_NMEAPARSER_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_NMEAPARSER_H

#include <iostream>
#include <string>
#include "../../data/GpsData.h"

class NmeaParser {
private:
    static bool checksumValidate(std::string& rawLine);
    static int detectMessageType(std::string& rawLine);
    static std::string extractField(std::string& rawLine);

    static void parseGga(std::string messageString, GpsData* gpsData);
    static void parseRmc(std::string messageString, GpsData* gpsData);
public:
    static void parseMessage(std::string messageString, GpsData* gpsData);
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_NMEAPARSER_H
