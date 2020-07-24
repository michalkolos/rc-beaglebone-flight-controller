//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_FLIGHTRECORD_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_FLIGHTRECORD_H


#include <vector>
#include "GpsData.h"
#include "CompassData.h"

class FlightRecord {
private:
    std::vector<GpsData> gpsDataVector;
    std::vector<CompassData> compassDataVector;
public:

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_FLIGHTRECORD_H
