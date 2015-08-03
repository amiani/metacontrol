//
// Created by ami on 30/07/15.
//

#include "FSCS.h"

void FSCS::turnOn() { state->turnOn(); }
void FSCS::mixLow() { state->mixLow(); }
void FSCS::mixHigh() { state->mixHigh(); }
void FSCS::sampleTimer() { state->sampleTimer(); }
void FSCS::referenceTimer() { state->referenceTimer(); }
void FSCS::turnOff() { state->turnOff(); }

bool FSCS::isMixHigh() {
    return LS5->isUp();
}
