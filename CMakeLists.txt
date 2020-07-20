cmake_minimum_required(VERSION 3.13)
project(rc_beaglebone_flight_controller)

set(CMAKE_CXX_STANDARD 14)

add_executable(rc_beaglebone_flight_controller
        main.cpp
        src/nav/Compass.cpp src/nav/Compass.h src/nav/Gps.cpp src/nav/Gps.h)