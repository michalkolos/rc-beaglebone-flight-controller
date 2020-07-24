//
// Created by kolos on 7/22/20.
//

#include "GpsData.h"

std::string GpsData::toString() {
    std::string outputString = GenericData::toString();
    outputString += "t: " + std::to_string(satelliteTime)
            + "/d: " + std::to_string(date)
            + "/lat: " + std::to_string(latitude) + latDirection
            + "/lon: " + std::to_string(longitude) + lonDirection
            + "/alt: " + std::to_string(altitudeAmsl)
            + "/spd: " + std::to_string(speedOverGround)
            + "/crs: " + std::to_string(courseOverGround)
            + "/#sats: " + std::to_string(numberOfSatellitesUsed)
            + "/hdop: " + std::to_string(hdop);

    return outputString;
}



int GpsData::getSatelliteTime() const {
    return satelliteTime;
}

void GpsData::setSatelliteTime(int satelliteTime) {
    GpsData::satelliteTime = satelliteTime;
}

int GpsData::getDate() const {
    return date;
}

void GpsData::setDate(int date) {
    GpsData::date = date;
}

float GpsData::getLatitude() const {
    return latitude;
}

void GpsData::setLatitude(float latitude) {
    GpsData::latitude = latitude;
}

char GpsData::getLatDirection() const {
    return latDirection;
}

void GpsData::setLatDirection(char latDirection) {
    GpsData::latDirection = latDirection;
}

float GpsData::getLongitude() const {
    return longitude;
}

void GpsData::setLongitude(float longitude) {
    GpsData::longitude = longitude;
}

char GpsData::getLonDirection() const {
    return lonDirection;
}

void GpsData::setLonDirection(char longDirection) {
    GpsData::lonDirection = longDirection;
}

int GpsData::getNumberOfSatellitesUsed() const {
    return numberOfSatellitesUsed;
}

void GpsData::setNumberOfSatellitesUsed(int numberOfSatellitesUsed) {
    GpsData::numberOfSatellitesUsed = numberOfSatellitesUsed;
}

float GpsData::getHdop() const {
    return hdop;
}

void GpsData::setHdop(float hdop) {
    GpsData::hdop = hdop;
}

float GpsData::getAltitudeAmsl() const {
    return altitudeAmsl;
}

void GpsData::setAltitudeAmsl(float altitudeAmsl) {
    GpsData::altitudeAmsl = altitudeAmsl;
}

float GpsData::getGeoidSeparation() const {
    return geoidSeparation;
}

void GpsData::setGeoidSeparation(float geoidSeparation) {
    GpsData::geoidSeparation = geoidSeparation;
}

float GpsData::getSpeedOverGround() const {
    return speedOverGround;
}

void GpsData::setSpeedOverGround(float speedOverGround) {
    GpsData::speedOverGround = speedOverGround;
}

float GpsData::getCourseOverGround() const {
    return courseOverGround;
}

void GpsData::setCourseOverGround(float courseOverGround) {
    courseOverGround = courseOverGround;
}


