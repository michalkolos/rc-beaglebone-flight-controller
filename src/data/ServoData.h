//
// Created by kolos on 7/28/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVODATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVODATA_H


#include <array>
#include "GenericData.h"

class ServoData : public GenericData{
private:
    static const int CHANNELS_NO = 8;
    static const int NEUTRAL_POS = 500;
    static const int MIN_POS = 0;
    static const int MAX_POS = 1000;

    std::array<int, CHANNELS_NO> channels{};

public:
    ServoData();
    int getChannel(int channelNo);
    void setChannel(int channelNo, int val);
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVODATA_H
