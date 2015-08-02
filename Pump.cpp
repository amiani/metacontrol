//
// Created by ami on 25/07/15.
//

#include "Pump.h"

void Pump::update() {
    if (topump >= 0) {
        float pumped = flowmeter->getReading();
        topump -= pumped;
    }
}

void Pump::pumpml(int ml) {
    topump = ml;
    flowmeter->resetCount();
}

void Pump::stop() { topump = 0; }

bool Pump::lock() {
    if (locked)
        return false;
    else {
        locked = true;
        return true;
    }
}

void Pump::unlock() {
    locked = false;
}

bool Pump::isLocked() {
    return locked;
}

float Pump::checkFlowmeter() {
    return flowmeter->getReading();
}