//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_GPSDATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_GPSDATA_H


#include "GenericData.h"

struct GpsFields{
    int satelliteTime = 0;
    int date = 0;
    float latitude = 0;
    char latDirection = ' ';
    float longitude = 0;
    char lonDirection = ' ';
    int numberOfSatellitesUsed = 0;
    float hdop = 0;
    float altitudeAmsl = 0;
    float geoidSeparation = 0;
    float speedOverGround = 0;
    float courseOverGround = 0;
};


class GpsData : public GenericData{
private:
    GpsFields fields;


public:
    GpsData() = default;
    explicit GpsData(const std::string &tag);


    GpsFields &getFields();
    void setFields(const GpsFields &fields);

    std::string toString();



//    int getSatelliteTime() const;
//
//    void setSatelliteTime(int time);
//
//    int getDate() const;
//
//    void setDate(int date);
//
//    float getLatitude() const;
//
//    void setLatitude(float latitude);
//
//    char getLatDirection() const;
//
//    void setLatDirection(char latDirection);
//
//    float getLongitude() const;
//
//    void setLongitude(float longitude);
//
//    char getLonDirection() const;
//
//    void setLonDirection(char lonDirection);
//
//    int getNumberOfSatellitesUsed() const;
//
//    void setNumberOfSatellitesUsed(int numberOfSatellitesUsed);
//
//    float getHdop() const;
//
//    void setHdop(float hdop);
//
//    float getAltitudeAmsl() const;
//
//    void setAltitudeAmsl(float altitudeAmsl);
//
//    float getGeoidSeparation() const;
//
//    void setGeoidSeparation(float geoidSeparation);
//
//    float getSpeedOverGround() const;
//
//    void setSpeedOverGround(float speedOverGround);
//
//    float getCourseOverGround() const;
//
//    void setCourseOverGround(float courseOverGround);

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_GPSDATA_H
