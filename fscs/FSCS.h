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
#include <vector>

class FSState;

class FSCS : public Machine {
public:
    FSCS(std::vector<Switch*> switches, std::vector<Sensor*> sensor, std::vector<Pump*> pumps)
            : Machine(new OffState, switches, sensors, pumps) {
        dynamic_cast<FSState*>(state);
        for (Switch* s : switches)
            if (s->getName() == "LS5")
                LS5 = s;
    };

    void turnOn();
    void mixLow();
    void mixHigh();
    void sampleTimer();
    void referenceTimer();
    void turnOff();

    bool isMixHigh();
    void checkTime(tm* gmt);

private:
    bool sampletime = false;
    bool referencetime = false;
    Switch* LS5;
};


#endif //METACONTROLSIM_FSCSMACHINE_H
