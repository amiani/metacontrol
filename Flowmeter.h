//
// Created by ami on 22/07/15.
//

#ifndef FSCSMOCK_FLOWMETER_H
#define FSCSMOCK_FLOWMETER_H


#include "Sensor.h"

class Flowmeter : public Sensor {
public:
    Flowmeter(std::unordered_map<std::string, std::string> attrs);
    float getReading();
    void resetCount() { count = 0; }
    void setKfactor(float kfactor);

private:
    int count = 0;
    std::string name;
    float kfactor;
};


#endif //FSCSMOCK_FLOWMETER_H
