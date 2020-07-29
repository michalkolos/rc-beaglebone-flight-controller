//
// Created by kolos on 7/22/20.
//

#include <chrono>
#include <utility>
#include "GenericData.h"

//void GenericData::setTimestampNow() {
//    timestamp = std::chrono::duration_cast<std::chrono::milliseconds>
//            (std::chrono::system_clock::now().time_since_epoch()).count();
//}

GenericData::GenericData(std::string tag) : tag(std::move(tag)) {}

GenericData::GenericData(GenericData &orgData) {
    tag = orgData.getTag();
}


std::string GenericData::toString() const {
    return tag + " // ";
}

const std::string &GenericData::getTag() const {
    return tag;
}

void GenericData::setTag(const std::string &tag) {
    GenericData::tag = tag;
}









