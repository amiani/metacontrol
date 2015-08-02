//
// Created by ami on 30/07/15.
//

#include "FSCS.h"

FSCS::FSCS(const FSCS& that) {
    this->state = that.state;
    this->sampletime = that.sampletime;
    this->referencetime = that.referencetime;
}

FSCS::~FSCS() {
    delete state;
}

void FSCS::turnOn() { state->turnOn(); }
void FSCS::mixLow() { state->mixLow(); }
void FSCS::mixHigh() { state->mixHigh(); }
void FSCS::sampleTimer() { state->sampleTimer(); }
void FSCS::referenceTimer() { state->referenceTimer(); }
void FSCS::turnOff() { state->turnOff(); }
