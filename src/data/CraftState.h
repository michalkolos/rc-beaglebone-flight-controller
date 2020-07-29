//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H


#include <mutex>
#include <vector>
#include "GpsData.h"
#include "CompassData.h"
#include "SerialData.h"
#include "SbusData.h"

class CraftState {
private:
    std::mutex accessMutex;
    std::vector<GenericData* > dataBank;

    SerialData serialData;
    GpsData gpsData;
    CompassData compassData;
    SbusData sbusData;

public:
    CraftState();

    unsigned int registerData(GenericData* newData);
    GenericData* getDataByTag(std::string tag);
    GenericData* getDataById(unsigned int id);



    SerialData &getSerialData();

    void setSerialData(const SerialData &serialData);

    GpsData &getGpsData();

    void setGpsData(const GpsData &gpsData);

    CompassData &getCompassData();

    void setCompassData(const CompassData &compassData);

    SbusData &getSbusData();

    void setSbusData(const SbusData &sbusData);
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_CRAFTSTATE_H
