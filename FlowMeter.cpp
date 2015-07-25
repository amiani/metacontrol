//
// Created by ami on 22/07/15.
//

#include "FlowMeter.h"

float FlowMeter::getReading() { return count * kfactor; }

void FlowMeter::setKfactor(float kfactor) { this->kfactor = kfactor; }
