//
// Created by kolos on 7/27/20.
//

#include "SbusData.h"

SbusData::SbusData(const std::string &tag) : GenericData(tag) {}


std::array<uint16_t, SbusData::_numChannels> &SbusData::getChannels(){
    return channels;
}

void SbusData::setChannels(const std::array<uint16_t, _numChannels> &channels) {
    accessMutex.lock();
    SbusData::channels = channels;
    accessMutex.unlock();
}

std::string SbusData::toString() {
    const int VALUE_LENGTH = 5;
    const char PADDING_SIGN = ' ';

    takeResource();

    std::string returnString = GenericData::toString();
    std::string valueString;

    for(unsigned short channel : channels){
        valueString = std::to_string(channel);
        valueString = std::string(VALUE_LENGTH - valueString.length(), PADDING_SIGN)
                + valueString
                + " ";

        returnString += valueString;
    }

    releaseResource();

    return returnString;
}




