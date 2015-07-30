//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_FSCSMACHINE_H
#define METACONTROLSIM_FSCSMACHINE_H
#include "FSState.h"


class FSCS {
public:
    FSCS();

    void turnOn() { state->turnOn(); }
    bool isMixHigh();
    void mixLow() { state->mixLow(); }
    void mixHigh() { state->mixHigh(); }
    void sampleTimer() { state->sampleTimer(); }
    void referenceTimer() { state->referenceTimer(); }
    void turnOff() { state->turnOff(); }

private:
    friend class FSState;
    FSState* state;
    bool sampletime = false;
    bool referencetime = false;
};


#endif //METACONTROLSIM_FSCSMACHINE_H
