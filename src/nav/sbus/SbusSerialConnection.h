//
// Created by kolos on 7/25/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SBUSSERIALCONNECTION_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SBUSSERIALCONNECTION_H


#include "../../interfaces/SerialConnection.h"

class SbusSerialConnection : public SerialConnection{

private:

    static const uint8_t _numChannels = 20;
    static const uint8_t _payloadSize = 24;

    static const uint8_t _sbusHeader = 0x0F;
    static const uint8_t _sbusFooter = 0x00;
    static const uint8_t _channel16 = 0x01;
    static const uint8_t _channel17 = 0x02;
    static const uint8_t _sbusLostFrame = 0x04;
    static const uint8_t _sbusFailSafe = 0x08;

    static const uint_fast8_t  FAILSAFE = 18;
    static const uint_fast8_t  LOST_FRAME = 19;


    /**
     * an Array of integers that holds decoded data. Must have the
     * length of at least 20:
     *      - 0 - 15:   16 analogue channels,
     *      - 16 - 17:  2 additional digital channels,
     *      - 18: failsafe activated bit,
     *      - 19: lost frame bit.
     */
//    std::array<uint16_t, _numChannels> channels{};
//    std::mutex channelsMutex;
    uint8_t frame[_payloadSize]{};
    int freshness;


    /**
     * @brief Reads raw data from the serial interface.
     *
     * @param frame - an array of bytes to store incoming data. Must be minimum 24
     * bytes long
     * @return bool: true - on success, false - on failure
     */
    bool readSbusFrame();

    /**
     * @brief Parses raw data into useful values representing separate control
     * channels
     *
     * @param frame - raw data received from the serial interface.
     * @return bool - true in normal operation, false when lost frame was detected.
     */
    bool sbusParse();

    /**
     * @brief Prints channel data to the console.
     **/


public:

    SbusSerialConnection(CraftState &craftState,
            const std::string &interfaceFilePath,
            bool startWorker);

    void read() override;
    void sbusPrint();
    void debug();
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SBUSSERIALCONNECTION_H
