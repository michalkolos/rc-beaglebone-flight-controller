//
// Created by kolos on 7/28/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVODATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVODATA_H


#include <array>
#include "GenericData.h"

class ServoData : public GenericData{
private:
    static const int MAX_CHANNELS_NO = 8;
    static const int DEFAULT_FREQ = 8;
    constexpr static const float NEUTRAL_POS_NORMALIZED = 0.5;

    int channelsNo;
    int pulseFreq;
    int minPosUs = 1000;
    int maxPosUs = 2000;

    bool interfaceRunning = false;
    std::array<float, MAX_CHANNELS_NO> channels{};


public:
    explicit ServoData(int channelsNo = MAX_CHANNELS_NO, int pulseFreq = DEFAULT_FREQ);

    float getChannel(int channelNo);
    void setChannel(int channelNo, float val);

    void setRange(int minPosUs, int maxPosUs);
    bool isInterfaceRunning() const;
    void setInterfaceRunning(bool interfaceRunning);
    int getMinPosUs() const;
    int getMaxPosUs() const;
    int getChannelsNo() const;
    void setChannelsNo(int channelsNo);
    int getPulseFreq() const;
    void setPulseFreq(int pulseFreq);


    std::string toString();
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERVODATA_H
