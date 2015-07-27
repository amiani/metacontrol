//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_SENSOR_H
#define FSCSMOCK_SENSOR_H
#include <string>
#include <unordered_map>

class Sensor {
public:
    Sensor(std::unordered_map<std::string, std::string> attrs) : attributes(attrs) {}
    virtual float getReading()=0;

protected:
    std::unordered_map<std::string, std::string> attributes;
};


#endif //FSCSMOCK_SENSOR_H
