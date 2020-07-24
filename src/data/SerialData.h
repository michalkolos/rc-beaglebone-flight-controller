//
// Created by kolos on 7/23/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERIALDATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERIALDATA_H


#include "GenericData.h"

class SerialData : public GenericData{
private:
    std::string data;

public:
    void record(std::string& newData);
    std::string toString();
    const std::string &getData() const;

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERIALDATA_H
