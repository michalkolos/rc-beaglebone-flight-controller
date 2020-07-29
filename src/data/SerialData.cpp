//
// Created by kolos on 7/23/20.
//

#include "SerialData.h"

void SerialData::record(std::string& newData) {
    data = newData;
}

std::string SerialData::toString() {
    std::string outputString = GenericData::toString();
    outputString += data;
    return outputString;
}

const std::string &SerialData::getData() const {
    return data;
}




