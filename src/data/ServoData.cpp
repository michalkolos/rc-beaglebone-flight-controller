//
// Created by kolos on 7/28/20.
//

#include "ServoData.h"

ServoData::ServoData(int channelsNo, int pulseFreq) :
    channelsNo(channelsNo), pulseFreq(pulseFreq), GenericData("SERVO") {

    for(float & channel : channels){
        channel = NEUTRAL_POS_NORMALIZED;
    }
}


float ServoData::getChannel(int channelNo) {
    return channels[channelNo];
}

void ServoData::setChannel(int channelNo, float val) {
    accessMutex.lock();
    if(val <= 1 && val >= 0){
        channels[channelNo] = val;
    }
    accessMutex.unlock();
}

void ServoData::setRange(int minPosUs, int maxPosUs) {
    accessMutex.lock();
    if(minPosUs >= 0 && maxPosUs >= 0 && maxPosUs > minPosUs) {
        this->minPosUs = minPosUs;
        this->maxPosUs = maxPosUs;
    }
    accessMutex.unlock();
}

bool ServoData::isInterfaceRunning() const {
    return interfaceRunning;
}

void ServoData::setInterfaceRunning(bool interfaceRunning) {
    ServoData::interfaceRunning = interfaceRunning;
}

int ServoData::getMinPosUs() const {
    return minPosUs;
}

int ServoData::getMaxPosUs() const {
    return maxPosUs;
}

int ServoData::getChannelsNo() const {
    return channelsNo;
}

void ServoData::setChannelsNo(int channelsNo) {
    ServoData::channelsNo = channelsNo;
}

int ServoData::getPulseFreq() const {
    return pulseFreq;
}

void ServoData::setPulseFreq(int pulseFreq) {
    ServoData::pulseFreq = pulseFreq;
}




std::string ServoData::toString() {
    accessMutex.lock();

    std::string outputString = GenericData::toString();

    if(interfaceRunning){
        outputString += " Enabled / ";
    }else{
        outputString += " Disabled / ";
    }

    for(int i = 0; i < channelsNo; i++){
        outputString += std::to_string(i) + ": " + std::to_string(channels[i]) + ", ";
    }

    accessMutex.unlock();

    return outputString;
}





