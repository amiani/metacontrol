//
// Created by ami on 22/07/15.
//

#ifndef FSCSMOCK_PUMP_H
#define FSCSMOCK_PUMP_H


#include <string>
#include <memory>
#include "FlowMeter.h"

class Pump {
public:
    Pump(std::string name, std::string port, FlowMeter* fm = nullptr) : name(name), flowmeter(fm) {}
    ~Pump() {
        delete flowmeter;
    }
    void start();
    void stop();
    bool lock();
    void unlock();

private:
    bool pumping = false;
    bool locked = false;
    std::string name;
    std::string output;
    FlowMeter* flowmeter;
};


#endif //FSCSMOCK_PUMP_H
