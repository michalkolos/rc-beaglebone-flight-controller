//
// Created by kolos on 7/22/20.
//

#include "CraftState.h"


SerialData &CraftState::getSerialData(){
    return serialData;
}

void CraftState::setSerialData(const SerialData &serialData) {
    CraftState::serialData = serialData;
}

GpsData &CraftState::getGpsData(){
    return gpsData;
}

void CraftState::setGpsData(const GpsData &gpsData) {
    CraftState::gpsData = gpsData;
}

CompassData &CraftState::getCompassData(){
    return compassData;
}

void CraftState::setCompassData(const CompassData &compassData) {
    CraftState::compassData = compassData;
}
