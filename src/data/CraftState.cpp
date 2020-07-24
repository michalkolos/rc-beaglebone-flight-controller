//
// Created by kolos on 7/22/20.
//

#include "CraftState.h"

GpsData *CraftState::getGpsData() const {
    return gpsData;
}

void CraftState::setGpsData(GpsData *gpsData) {
    CraftState::gpsData = gpsData;
}

CompassData *CraftState::getCompassData() const {
    return compassData;
}

void CraftState::setCompassData(CompassData *compassData) {
    CraftState::compassData = compassData;
}

CraftState::~CraftState() {
    delete compassData;
    delete gpsData;
}
