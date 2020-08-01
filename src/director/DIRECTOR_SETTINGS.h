//
// Created by kolos on 8/1/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_DIRECTOR_SETTINGS_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_DIRECTOR_SETTINGS_H

#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_DIRECTOR_SETTINGS_H

struct DIRECTOR_SETTINGS{
    static const int THROTTLE_SBUS = 0;
    static const int THROTTLE_SERVO = 0;

    static const int AILERON_SBUS = 1;
    static const int AILERON_LEFT_SERVO = 1;
    static const int AILERON_RIGHT_SERVO = 2;

    static const int ELEVATOR_SBUS = 2;
    static const int ELEVATOR_SERVO = 3;

};