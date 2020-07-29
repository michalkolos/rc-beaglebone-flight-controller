cmake_minimum_required(VERSION 3.13)
project(rc_beaglebone_flight_controller)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(rc_beaglebone_flight_controller
        main.cpp
        src/nav/Compass.cpp src/nav/Compass.h
        src/nav/gps/GpsSerialConnection.cpp src/nav/gps/GpsSerialConnection.h
        src/nav/gps/NmeaParser.cpp src/nav/gps/NmeaParser.h src/data/GpsData.cpp src/data/GpsData.h src/data/CompassData.cpp src/data/CompassData.h src/data/FlightRecord.cpp src/data/FlightRecord.h src/data/CraftState.cpp src/data/CraftState.h src/data/GenericData.cpp src/data/GenericData.h src/interfaces/SerialConnection.cpp src/interfaces/SerialConnection.h src/data/SerialData.cpp src/data/SerialData.h src/nav/sbus/SbusSerialConnection.cpp src/nav/sbus/SbusSerialConnection.h src/data/SbusData.cpp src/data/SbusData.h src/utils/Utils.cpp src/utils/Utils.h src/servo/ServoController.cpp src/servo/ServoController.h src/worker/WorkerThread.cpp src/worker/WorkerThread.h src/data/ServoData.cpp src/data/ServoData.h)


target_link_libraries(rc_beaglebone_flight_controller Threads::Threads)
