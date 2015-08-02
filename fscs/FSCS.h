//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_FSCSMACHINE_H
#define METACONTROLSIM_FSCSMACHINE_H

#include "FSState.h"
#include "../Machine.h"
#include <string>

class FSState;

class FSCS : public Machine {
public:
    FSCS() : state(new OffState()) {};
    FSCS(const FSCS&);
    ~FSCS();

    void turnOn();
    void mixLow();
    void mixHigh();
    void sampleTimer();
    void referenceTimer();
    void turnOff();

    bool isMixHigh();
    void checkReading(std::string name, float reading);
    void checkTime(tm* gmt);

private:
    friend class FSState;
    bool sampletime = false;
    bool referencetime = false;
};


#endif //METACONTROLSIM_FSCSMACHINE_H
