//
// Created by ami on 23/07/15.
//

#ifndef FSCSMOCK_LEVELSENSOR_H
#define FSCSMOCK_LEVELSENSOR_H


#include "Sensor.h"

class LevelSensor : public Sensor {
public:
    float getReading();
private:
    int isup = 0;
};


#endif //FSCSMOCK_LEVELSENSOR_H
