//
// Created by kolos on 7/27/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SBUSDATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SBUSDATA_H


#include <array>
#include <mutex>
#include "GenericData.h"

class SbusData : public GenericData {

private:
    static const uint8_t _numChannels = 20;



    /**
     * an Array of integers that holds decoded data. Must have the
     * length of at least 20:
     *      - 0 - 15:   16 analogue channels,
     *      - 16 - 17:  2 additional digital channels,
     *      - 18: failsafe activated bit,
     *      - 19: lost frame bit.
     */
    std::array<uint16_t, _numChannels> channels{};


public:
    SbusData() = default;
    explicit SbusData(const std::string &tag);

    std::string toString();
    std::array<uint16_t, _numChannels> &getChannels();

    void setChannels(const std::array<uint16_t, _numChannels> &channels);

};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SBUSDATA_H
