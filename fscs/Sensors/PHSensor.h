//
// Created by ami on 23/07/15.
//

#ifndef MOCKCONTROLSYSTEM_PHSENSOR_H
#define MOCKCONTROLSYSTEM_PHSENSOR_H


#include "../../Sensor.h"

class PHSensor : public Sensor {
public:
    float getReading() { return ph; }
private:
    float ph = 7;
};


#endif //MOCKCONTROLSYSTEM_PHSENSOR_H
