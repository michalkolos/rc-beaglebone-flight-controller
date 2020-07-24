//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_COMPASSDATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_COMPASSDATA_H


#include "GenericData.h"

class CompassData : public GenericData{
private:
    int xVal = 0;
    int yVal = 0;
    int zVal = 0;

public:
    CompassData();
    CompassData(int xVal, int yVal, int zVal);

    std::string toString();

    int getXVal() const;

    void setXVal(int xVal);

    int getYVal() const;

    void setYVal(int yVal);

    int getZVal() const;

    void setZVal(int zVal);
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_COMPASSDATA_H
