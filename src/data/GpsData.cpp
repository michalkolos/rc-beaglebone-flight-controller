//
// Created by kolos on 7/22/20.
//

#include "GpsData.h"


GpsData::GpsData(const std::string &tag) : GenericData(tag) {}


std::string GpsData::toString() {
    accessMutex.lock();
    std::string outputString = GenericData::toString();
    outputString += "t: " + std::to_string(fields.satelliteTime)
            + "/d: " + std::to_string(fields.date)
            + "/lat: " + std::to_string(fields.latitude) + fields.latDirection
            + "/lon: " + std::to_string(fields.longitude) + fields.lonDirection
            + "/alt: " + std::to_string(fields.altitudeAmsl)
            + "/spd: " + std::to_string(fields.speedOverGround)
            + "/crs: " + std::to_string(fields.courseOverGround)
            + "/#sats: " + std::to_string(fields.numberOfSatellitesUsed)
            + "/hdop: " + std::to_string(fields.hdop);
    accessMutex.unlock();

    return outputString;
}



//int GpsData::getSatelliteTime() const {
//    return satelliteTime;
//}
//
//void GpsData::setSatelliteTime(int satelliteTime) {
//    GpsData::satelliteTime = satelliteTime;
//}
//
//int GpsData::getDate() const {
//    return date;
//}
//
//void GpsData::setDate(int date) {
//    GpsData::date = date;
//}
//
//float GpsData::getLatitude() const {
//    return latitude;
//}
//
//void GpsData::setLatitude(float latitude) {
//    GpsData::latitude = latitude;
//}
//
//char GpsData::getLatDirection() const {
//    return latDirection;
//}
//
//void GpsData::setLatDirection(char latDirection) {
//    GpsData::latDirection = latDirection;
//}
//
//float GpsData::getLongitude() const {
//    return longitude;
//}
//
//void GpsData::setLongitude(float longitude) {
//    GpsData::longitude = longitude;
//}
//
//char GpsData::getLonDirection() const {
//    return lonDirection;
//}
//
//void GpsData::setLonDirection(char longDirection) {
//    GpsData::lonDirection = longDirection;
//}
//
//int GpsData::getNumberOfSatellitesUsed() const {
//    return numberOfSatellitesUsed;
//}
//
//void GpsData::setNumberOfSatellitesUsed(int numberOfSatellitesUsed) {
//    GpsData::numberOfSatellitesUsed = numberOfSatellitesUsed;
//}
//
//float GpsData::getHdop() const {
//    return hdop;
//}
//
//void GpsData::setHdop(float hdop) {
//    GpsData::hdop = hdop;
//}
//
//float GpsData::getAltitudeAmsl() const {
//    return altitudeAmsl;
//}
//
//void GpsData::setAltitudeAmsl(float altitudeAmsl) {
//    GpsData::altitudeAmsl = altitudeAmsl;
//}
//
//float GpsData::getGeoidSeparation() const {
//    return geoidSeparation;
//}
//
//void GpsData::setGeoidSeparation(float geoidSeparation) {
//    GpsData::geoidSeparation = geoidSeparation;
//}
//
//float GpsData::getSpeedOverGround() const {
//    return speedOverGround;
//}
//
//void GpsData::setSpeedOverGround(float speedOverGround) {
//    GpsData::speedOverGround = speedOverGround;
//}
//
//float GpsData::getCourseOverGround() const {
//    return courseOverGround;
//}
//
//void GpsData::setCourseOverGround(float courseOverGround) {
//    courseOverGround = courseOverGround;
//}


const GpsFields &GpsData::getFields() const {
    return fields;
}

void GpsData::setFields(const GpsFields &fields) {
    accessMutex.lock();
    GpsData::fields = fields;
    accessMutex.unlock();
}


