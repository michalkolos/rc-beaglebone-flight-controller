//
// Created by kolos on 7/28/20.
//

#include "ServoData.h"

ServoData::ServoData(){
    for(int channel : channels){
        channel = NEUTRAL_POS;
    }
}

int ServoData::getChannel(int channelNo) {
    return channels[channelNo];
}

void ServoData::setChannel(int channelNo, int val) {
    if(val <= MAX_POS && val >= MIN_POS){
        channels[channelNo] = val;
    }
}
