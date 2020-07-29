//
// Created by kolos on 7/20/20.
//

#include "GpsSerialConnection.h"

GpsSerialConnection::GpsSerialConnection(CraftState& craftState,
     const std::string &interfaceFilePath, int baudRate, bool startWorker, int parityBit,
     int stopBits, int hardwareFlowControl, int bitsPerByte) :
        SerialConnection(craftState, interfaceFilePath, baudRate, startWorker, parityBit,
            stopBits, hardwareFlowControl, bitsPerByte) {

    gpsData = new GpsData(DATA_TAG);
    registerNewData(gpsData);

}

void GpsSerialConnection::read() {
    std::string incomingData = readSerialLine();
    NmeaParser::parseMessage(incomingData, gpsData);
}


