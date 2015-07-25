//
// Created by ami on 23/07/15.
//

#ifndef MOCKCONTROLSYSTEM_TEMPSENSOR_H
#define MOCKCONTROLSYSTEM_TEMPSENSOR_H


#include "../../Sensor.h"

class TempSensor : public Sensor {
public:
    float getReading() { return temp; }
private:
    float temp;

};


#endif //MOCKCONTROLSYSTEM_TEMPSENSOR_H
