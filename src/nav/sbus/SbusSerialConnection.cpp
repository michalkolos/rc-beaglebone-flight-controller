//
// Created by kolos on 7/25/20.
//

#include "SbusSerialConnection.h"
#include "../../utils/Utils.h"

SbusSerialConnection::SbusSerialConnection(CraftState &craftState,
    const std::string &interfaceFilePath, bool startWorker) :
        SerialConnection(craftState, interfaceFilePath, 100000,
            startWorker, 1,1, 0, 8) {

    sbusData = new SbusData(DATA_TAG);

    registerNewData(sbusData);
}

void SbusSerialConnection::read() {
    if(readSbusFrame()){
        sbusParse();
    }
}






bool SbusSerialConnection::readSbusFrame() {

    char byteBuffer[1];
    char prevByte = _sbusFooter;
    int frameCouter = 0;

    while(frameCouter < _payloadSize){
        int len = ::read(fileDescriptor, byteBuffer, sizeof(byteBuffer));

        if(len < 0){
            printf("Error %i from read: %s\n", errno, strerror(errno));
            return false;
        }

        if(byteBuffer[0] == _sbusHeader && prevByte == _sbusFooter){
            frameCouter = 0;
        }else{
            frame[frameCouter] = (uint8_t)byteBuffer[0];
            frameCouter++;
        }

        prevByte = byteBuffer[0];
    }
     return true;
 }

// TODO: Create lost SBUS frames counter.

bool SbusSerialConnection::sbusParse() {

    sbusData->takeResource();
    std::array<uint16_t, _numChannels>& channels = sbusData->getChannels();


//    std::array<uint16_t, _numChannels> channels;

    channels[0]  = (uint16_t) ((frame[0]       | frame[1] << 8)                     & 0x07FF) - 172;
    channels[1]  = (uint16_t) ((frame[1] >> 3  | frame[2] << 5)                     & 0x07FF) - 172;
    channels[2]  = (uint16_t) ((frame[2] >> 6  | frame[3] << 2 | frame[4] << 10)    & 0x07FF) - 172;
    channels[3]  = (uint16_t) ((frame[4] >> 1  | frame[5] << 7)                     & 0x07FF) - 172;
    channels[4]  = (uint16_t) ((frame[5] >> 4  | frame[6] << 4)                     & 0x07FF) - 172;
    channels[5]  = (uint16_t) ((frame[6] >> 7  | frame[7] << 1 | frame[8] << 9)     & 0x07FF) - 172;
    channels[6]  = (uint16_t) ((frame[8] >> 2  | frame[9] << 6)                     & 0x07FF) - 172;
    channels[7]  = (uint16_t) ((frame[9] >> 5  | frame[10] << 3)                    & 0x07FF) - 172;
    channels[8]  = (uint16_t) ((frame[11]      | frame[12] << 8)                    & 0x07FF) - 172;
    channels[9]  = (uint16_t) ((frame[12] >> 3 | frame[13] << 5)                    & 0x07FF) - 172;
    channels[10] = (uint16_t) ((frame[13] >> 6 | frame[14] << 2 | frame[15] << 10)  & 0x07FF) - 172;
    channels[11] = (uint16_t) ((frame[15] >> 1 | frame[16] << 7)                    & 0x07FF) - 172;
    channels[12] = (uint16_t) ((frame[16] >> 4 | frame[17] << 4)                    & 0x07FF) - 172;
    channels[13] = (uint16_t) ((frame[17] >> 7 | frame[18] << 1 | frame[19] << 9)   & 0x07FF) - 172;
    channels[14] = (uint16_t) ((frame[19] >> 2 | frame[20] << 6)                    & 0x07FF) - 172;
    channels[15] = (uint16_t) ((frame[20] >> 5 | frame[21] << 3)                    & 0x07FF) - 172;



    if(frame[22] & _channel16) {
        channels[16] = 1;
    } else {
        channels[16] = 0;
    }

    if(frame[22] & _channel17) {
        channels[17] = 1;
    } else {
        channels[17] = 0;
    }

    if (frame[22] & _sbusFailSafe) {
        channels[FAILSAFE] = 1;
    } else {
        channels[FAILSAFE] = 0;
    }


    if (frame[22] & _sbusLostFrame) {
        channels[LOST_FRAME] = 1;
        sbusData->releaseResource();
        return -1;
    } else {
        channels[LOST_FRAME] = 0;
    }

    sbusData->releaseResource();

//    sbusData->setChannels(channels);
    return true;
}


void SbusSerialConnection::debug() {
    char byteBuffer[1];
    while(true) {
        int len = ::read(fileDescriptor, byteBuffer, sizeof(byteBuffer));
//        if(byteBuffer[0] == 0){ std::cout << std::endl; }
//        std::cout << (int)byteBuffer[0] << " ";
    }


}


