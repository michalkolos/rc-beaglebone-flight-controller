//
// Created by kolos on 7/22/20.
//

#include "CompassData.h"

CompassData::CompassData()  : GenericData(){

}

CompassData::CompassData(int xVal, int yVal, int zVal) : GenericData(),
xVal(xVal), yVal(yVal), zVal(zVal) {

}

std::string CompassData::toString() {
    std::string outString = GenericData::toString();
    outString += " x: " + std::to_string(xVal)
            + " / y: " + std::to_string(yVal)
            + " / z: " + std::to_string(zVal);

    return outString;
}


int CompassData::getXVal() const {
    return xVal;
}

void CompassData::setXVal(int xVal) {
    CompassData::xVal = xVal;
}

int CompassData::getYVal() const {
    return yVal;
}

void CompassData::setYVal(int yVal) {
    CompassData::yVal = yVal;
}

int CompassData::getZVal() const {
    return zVal;
}

void CompassData::setZVal(int zVal) {
    CompassData::zVal = zVal;
}


