//
// Created by ami on 23/07/15.
//

#ifndef MOCKCONTROLSYSTEM_WETTRAYSENSOR_H
#define MOCKCONTROLSYSTEM_WETTRAYSENSOR_H


#include "../../Sensor.h"

class WetTraySensor : public Sensor {
public:
    WetTraySensor(std::unordered_map<std::string, std::string> attrs) : Sensor(attrs) {}
    float getReading() { return iswet; }
private:
    bool iswet = false;
};


#endif //MOCKCONTROLSYSTEM_WETTRAYSENSOR_H
