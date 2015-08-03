//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_FSCSMACHINE_H
#define METACONTROLSIM_FSCSMACHINE_H

#include "FSState.h"
#include "../Machine.h"
#include "../Pump.h"
#include "../Switch.h"
#include <string>
#include <unordered_map>

class FSState;

class FSCS : public Machine {
public:
    FSCS(std::unordered_map<std::string, Switch*> switches, std::unordered_map<std::string, Sensor*> sensor, std::unordered_map<std::string, Pump*> pumps)
            : Machine(new OffState(this), switches, sensors, pumps) {
        LS5 = switches["LS5"];
    };

    void turnOn();
    void mixLow();
    void mixHigh();
    void sampleTimer();
    void referenceTimer();
    void turnOff();

    void checkTime(tm* gmt);

private:
    friend class FSState;
    Switch* LS5;
    bool sampletime = false;
    bool referencetime = false;
};


#endif //METACONTROLSIM_FSCSMACHINE_H
