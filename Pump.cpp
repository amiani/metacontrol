//
// Created by ami on 22/07/15.
//

#include "Pump.h"

void Pump::start() {
    pumping = true;
}

void Pump::stop() { pumping = false; }

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
