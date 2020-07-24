//
// Created by kolos on 7/20/20.
//

#include "GpsSerialConnection.h"

GpsSerialConnection::GpsSerialConnection(const std::string &interfaceFilePath,
     int baudRate, int parityBit, int stopBits, int hardwareFlowControl,
     int bitsPerByte) :
        SerialConnection(interfaceFilePath, baudRate, parityBit, stopBits,
                         hardwareFlowControl, bitsPerByte) {

}

void GpsSerialConnection::read(GpsData& gpsData) {
    std::string incomingData = readSerialLine();
    NmeaParser::parseMessage(incomingData, gpsData);
}


