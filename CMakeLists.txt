cmake_minimum_required(VERSION 3.13)
project(rc_beaglebone_flight_controller)

set(CMAKE_CXX_STANDARD 14)



add_executable(rc_beaglebone_flight_controller
        main.cpp
        src/nav/Compass.cpp src/nav/Compass.h
        src/nav/gps/GpsSerialConnection.cpp src/nav/gps/GpsSerialConnection.h
        src/nav/gps/NmeaParser.cpp src/nav/gps/NmeaParser.h src/data/GpsData.cpp src/data/GpsData.h src/data/CompassData.cpp src/data/CompassData.h src/data/FlightRecord.cpp src/data/FlightRecord.h src/data/CraftState.cpp src/data/CraftState.h src/data/GenericData.cpp src/data/GenericData.h src/interfaces/SerialConnection.cpp src/interfaces/SerialConnection.h src/data/SerialData.cpp src/data/SerialData.h)
