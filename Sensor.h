//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_SENSOR_H
#define FSCSMOCK_SENSOR_H
#include <string>
#include <unordered_map>

class Sensor {
public:
    Sensor(std::unordered_map<std::string, std::string> attrs) : attributes(attrs) {
        name = attributes.at("name");
    }
    virtual float getReading()=0;
    std::string getName() { return name; }

protected:
    std::unordered_map<std::string, std::string> attributes;
    std::string name;
};


#endif //FSCSMOCK_SENSOR_H
