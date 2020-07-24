//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDATA_H

#include <string>

class GenericData {
private:
    unsigned long timestamp = 0;
public:
    GenericData();
    void setTimestampNow();
    unsigned long getTimestamp() const;
    std::string toString() const;



};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDATA_H
