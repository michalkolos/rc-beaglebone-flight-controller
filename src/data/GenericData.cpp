//
// Created by kolos on 7/22/20.
//

#include <chrono>
#include "GenericData.h"

void GenericData::setTimestampNow() {
    timestamp = std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now().time_since_epoch()).count();
}

unsigned long GenericData::getTimestamp() const {
    return timestamp;
}

GenericData::GenericData() {
    setTimestampNow();
}

std::string GenericData::toString() const {
    return std::to_string(timestamp) + " // ";
}
