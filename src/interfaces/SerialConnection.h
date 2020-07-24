//
// Created by kolos on 7/23/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERIALCONNECTION_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERIALCONNECTION_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <cerrno> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <thread>
#include "../data/SerialData.h"
#include "../data/CraftState.h"

class SerialConnection {
private:
    int fileDescriptor;
    std::thread workerThread;
    bool threadRunning = false;

protected:
    CraftState& craftState;
    void workerFunction();
    std::string readSerialLine() const;

    bool startThread();
    bool stopThread();

public:
    SerialConnection(CraftState& craftState,
           const std::string& interfaceFilePath,
           int baudRate,
           bool startWorker,
           int parityBit = 0,
           int stopBits = 0,
           int hardwareFlowControl = 0,
           int bitsPerByte = 8);

    virtual ~SerialConnection();

    void write(const std::string& writeString) const;

    virtual void read();
    void close() const;
};


#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_SERIALCONNECTION_H
