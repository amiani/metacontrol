//
// Created by ami on 22/07/15.
//

#ifndef FSCSMOCK_FLOWMETER_H
#define FSCSMOCK_FLOWMETER_H


#include "Sensor.h"

class FlowMeter : public Sensor {
public:
    FlowMeter(std::string port) : Sensor(port), count(0), kfactor(1.3) {}
    float getReading();
    void setKfactor(float kfactor);

private:
    int count = 0;
    std::string name;
    float kfactor;
};


#endif //FSCSMOCK_FLOWMETER_H
