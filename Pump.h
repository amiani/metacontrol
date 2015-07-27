//
// Created by ami on 22/07/15.
//

#ifndef FSCSMOCK_PUMP_H
#define FSCSMOCK_PUMP_H


#include <string>
#include <memory>
#include "FlowMeter.h"
#include <unordered_map>

class Pump {
public:
    Pump(std::unordered_map<std::string, std::string> attrs);
    ~Pump() {
        delete flowmeter;
    }
    void update();
    void pumpml(int ml);
    void stop();
    bool lock();
    void unlock();

private:
    bool locked = false;
    int topump = 0;
    int checkFlowmeter();
    std::string name;
    std::string port;
    FlowMeter* flowmeter;
};


#endif //FSCSMOCK_PUMP_H
