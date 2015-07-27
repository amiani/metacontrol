//
// Created by ami on 27/07/15.
//

#ifndef METACONTROLSIM_TESTSENSOR_H
#define METACONTROLSIM_TESTSENSOR_H


#include "Sensor.h"

class TestSensor : public Sensor {
public:
    TestSensor(std::unordered_map<std::string, std::string> attrs) : Sensor(attrs) {}
    float getReading() { return 10; }

private:
};


#endif //METACONTROLSIM_TESTSENSOR_H
