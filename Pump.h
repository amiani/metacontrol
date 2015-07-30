//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_PUMP_H
#define FSCSMOCK_PUMP_H


#include <string>
#include <memory>
#include "Flowmeter.h"
#include <unordered_map>

class Pump {
public:
    Pump(std::unordered_map<std::string, std::string> attrs, Flowmeter* fm)
            : attributes(attrs), flowmeter(fm) {}
    Pump(std::unordered_map<std::string, std::string> attrs) : Pump(attrs, nullptr) {}
    ~Pump() {
        delete flowmeter;
    }
    virtual void update();
    virtual void pumpml(int ml);
    void stop();
    bool lock();
    void unlock();
    bool isLocked();

protected:
    std::unordered_map<std::string, std::string> attributes;
    int topump = 0;

private:
    bool locked = false;
    int checkFlowmeter();
    Flowmeter * flowmeter;
};


#endif //FSCSMOCK_PUMP_H
