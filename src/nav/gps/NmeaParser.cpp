//
// Created by kolos on 7/21/20.
//

#include <cstring>
#include "NmeaParser.h"

void NmeaParser::parseMessage(std::string messageString, GpsData* gpsData) {

    if(!checksumValidate(messageString)){ return; }
    int messageType = detectMessageType(messageString);

    if(messageType == 1){ parseGga(messageString, gpsData); }
    if(messageType == 2){ parseRmc(messageString, gpsData); }

}

int NmeaParser::detectMessageType(std::string &rawLine) {

    int messageId = 0;
    std::string messageTag = extractField(rawLine);
//    messageTag = messageTag.substr(3, 3);
    messageTag = messageTag.substr(messageTag.size() - 3);

    if(messageTag  == "GGA") {messageId = 1; }
    else if(messageTag == "RMC") {messageId = 2; }

    return messageId;
}

std::string NmeaParser::extractField(std::string &rawLine) {

    size_t nextComaIndex = rawLine.find_first_of(",\r");

    std::string field = rawLine.substr(0, nextComaIndex);

    if(nextComaIndex < std::string::npos) { nextComaIndex++; }
    rawLine.erase(0, nextComaIndex);

//    std::cout << field << "===";

//    if(field.empty()){ field = "0"; }

    return field;
}

bool NmeaParser::checksumValidate(std::string &rawLine) {

    size_t checksumPos = rawLine.find('*');
    size_t checksumEnd = rawLine.find('\r');

    if(checksumPos == 0 || checksumPos == std::string::npos){ return false; }

    int calculatedChecksum = 0;
    for(int i = 1; i < checksumPos; i++){
        calculatedChecksum ^= rawLine[i];
    }

    std::string checksumString = rawLine.substr(checksumPos + 1, checksumEnd - checksumPos - 1);
    int checksum;
    try {
        checksum = std::stoi(checksumString, nullptr, 16);
    } catch (std::exception e) {
        return false;
    }

    rawLine.erase(checksumPos, checksumEnd - 1);

    return checksum == calculatedChecksum;
}

void NmeaParser::parseGga(std::string messageString, GpsData* gpsData) {

    GpsFields gpsFields = gpsData->getFields();

    try {

        gpsFields.satelliteTime = (int) std::stof(extractField(messageString)) * 100;
        gpsFields.latitude = std::stof(extractField(messageString));
        gpsFields.latDirection = extractField(messageString)[0];
        gpsFields.longitude = std::stof(extractField(messageString));
        gpsFields.lonDirection = extractField(messageString)[0];
        extractField(messageString);
        gpsFields.numberOfSatellitesUsed = std::stoi(extractField(messageString));
        gpsFields.hdop = std::stof(extractField(messageString));
        gpsFields.altitudeAmsl = std::stof(extractField(messageString));
        extractField(messageString);
        gpsFields.geoidSeparation = std::stof(extractField(messageString));

//        gpsData.setSatelliteTime((int) std::stof(extractField(messageString)) * 100);
//        gpsData.setLatitude(std::stof(extractField(messageString)));
//        gpsData.setLatDirection(extractField(messageString)[0]);
//        gpsData.setLongitude(std::stof(extractField(messageString)));
//        gpsData.setLonDirection(extractField(messageString)[0]);
//        extractField(messageString);
//        gpsData.setNumberOfSatellitesUsed(std::stoi(extractField(messageString)));
//        gpsData.setHdop(std::stof(extractField(messageString)));
//        gpsData.setAltitudeAmsl(std::stof(extractField(messageString)));
//        extractField(messageString);
//        gpsData.setGeoidSeparation(std::stof(extractField(messageString)));

    } catch (std::exception& e) {
//        std::cout << "Exception in parsing NMEA GGA message: " << e.what() << std::endl;
    }

    gpsData->setFields(gpsFields);
}

// TODO: Parsing some of the fields might be redundant as no new information is conveyed.
void NmeaParser::parseRmc(std::string messageString, GpsData* gpsData) {

    GpsFields gpsFields = gpsData->getFields();

    try {

        gpsFields.satelliteTime = (int)std::stof(extractField(messageString)) * 100;
        extractField(messageString); // TODO: Check NMEA message status field.
        gpsFields.latitude = std::stof(extractField(messageString));
        gpsFields.latDirection = extractField(messageString)[0];
        gpsFields.longitude = std::stof(extractField(messageString));
        gpsFields.lonDirection = extractField(messageString)[0];
        gpsFields.speedOverGround = std::stof(extractField(messageString));
        gpsFields.courseOverGround = std::stof(extractField(messageString));
        gpsFields.date = std::stoi(extractField(messageString));


//        gpsData.setSatelliteTime((int)std::stof(extractField(messageString)) * 100);
//        extractField(messageString); // TODO: Check NMEA message status field.
//        gpsData.setLatitude(std::stof(extractField(messageString)));
//        gpsData.setLatDirection(extractField(messageString)[0]);
//        gpsData.setLongitude(std::stof(extractField(messageString)));
//        gpsData.setLonDirection(extractField(messageString)[0]);
//        gpsData.setSpeedOverGround(std::stof(extractField(messageString)));
//        gpsData.setCourseOverGround(std::stof(extractField(messageString)));
//        gpsData.setDate(std::stoi(extractField(messageString)));

    } catch (std::exception& e) {
//        std::cout << "Exception in parsing NMEA RMC message: " << e.what() << std::endl;
    }

    gpsData->setFields(gpsFields);
}



