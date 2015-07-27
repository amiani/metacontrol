//
// Created by ami on 7/26/15.
//

#ifndef METACONTROLSIM_ECSENSOR_H
#define METACONTROLSIM_ECSENSOR_H


#include "../../Sensor.h"

class ECSensor : public Sensor {
public:
    ECSensor(std::unordered_map<std::string, std::string> attrs);

};


#endif //METACONTROLSIM_ECSENSOR_H
