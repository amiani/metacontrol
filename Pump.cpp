//
// Created by ami on 22/07/15.
//

#include "Pump.h"

Pump::Pump(std::unordered_map<std::string, std::string> attrs, Flowmeter* flowmeter)
        : flowmeter(flowmeter) {
    name = attrs["name"];
    port = attrs["port"];
}

void Pump::update() {
    if (topump >= 0)
        flowmeter->getReading();
        //send current
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