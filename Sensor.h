//
// Created by ami on 23/07/15.
//

#ifndef FSCSMOCK_SENSOR_H
#define FSCSMOCK_SENSOR_H
#include <string>

class Sensor {
public:
    Sensor();
    Sensor(std::string port) : port(port) {}
    virtual float getReading()=0;

protected:
    std::string port;
};


#endif //FSCSMOCK_SENSOR_H
