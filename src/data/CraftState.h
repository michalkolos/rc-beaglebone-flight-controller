//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H


#include "GpsData.h"
#include "CompassData.h"

class CraftState {
private:
    GpsData* gpsData = nullptr;
    CompassData* compassData = nullptr;

public:

    virtual ~CraftState();

    GpsData *getGpsData() const;

    void setGpsData(GpsData *gpsData);

    CompassData *getCompassData() const;

    void setCompassData(CompassData *compassData);
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H
