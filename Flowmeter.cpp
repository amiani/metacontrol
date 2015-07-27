//
// Created by ami on 22/07/15.
//

#include "Flowmeter.h"

float Flowmeter::getReading() { return count * kfactor; }

void Flowmeter::setKfactor(float kfactor) { this->kfactor = kfactor; }
