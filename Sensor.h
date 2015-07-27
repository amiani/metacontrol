//
// Created by ami on 23/07/15.
//

#ifndef FSCSMOCK_SENSOR_H
#define FSCSMOCK_SENSOR_H
#include <string>
#include <unordered_map>

class Sensor {
public:
    Sensor(std::unordered_map<std::string, std::string> attrs);
    virtual float getReading()=0;

protected:
    std::string name;
    std::string port;
};


#endif //FSCSMOCK_SENSOR_H
