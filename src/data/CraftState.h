//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H


#include "GpsData.h"
#include "CompassData.h"
#include "SerialData.h"

class CraftState {
private:
    SerialData serialData;
    GpsData gpsData;
    CompassData compassData;

public:
    SerialData &getSerialData();

    void setSerialData(const SerialData &serialData);

    GpsData &getGpsData();

    void setGpsData(const GpsData &gpsData);

    CompassData &getCompassData();

    void setCompassData(const CompassData &compassData);
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H
