//
// Created by kolos on 7/22/20.
//

#include "CraftState.h"

CraftState::CraftState() {
    dataBank.push_back(new GenericData("NO_DATA"));
}

SerialData &CraftState::getSerialData(){
    return serialData;
}

void CraftState::setSerialData(const SerialData &serialData) {
//    CraftState::serialData = serialData;
}

GpsData &CraftState::getGpsData(){
    return gpsData;
}

void CraftState::setGpsData(const GpsData &gpsData) {
//    CraftState::gpsData = gpsData;
}

CompassData &CraftState::getCompassData(){
    return compassData;
}

void CraftState::setCompassData(const CompassData &compassData) {
//    CraftState::compassData = compassData;
}

SbusData &CraftState::getSbusData(){
    return sbusData;
}

void CraftState::setSbusData(const SbusData &sbusData) {
//    CraftState::sbusData = sbusData;
}




unsigned int CraftState::registerData(GenericData* newData) {
    accessMutex.lock();
    dataBank.push_back(newData);
    unsigned int newId = dataBank.size() - 1;
    accessMutex.unlock();

    return newId;
}

GenericData* CraftState::getDataByTag(std::string tag) {
    accessMutex.lock();
    GenericData* returnData;

    for(auto & genericData : dataBank){
        if(tag == genericData->getTag()){
            returnData =  genericData;
            accessMutex.unlock();
            return returnData;
        }
    }
    returnData = dataBank.at(0);
    accessMutex.unlock();

    return returnData;
}

GenericData* CraftState::getDataById(unsigned int id) {
    if(id < dataBank.size()){
        return dataBank.at(id);
    }
    return dataBank.at(0);
}

