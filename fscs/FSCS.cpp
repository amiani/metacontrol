//
// Created by ami on 04/08/15.
//

#include "FSCS.h"

FSCS::FSCS(IOMaps r) : Machine(std::unique_ptr<OffState>(new OffState(getThis())), r) {
    LS5 = switches["LS5"];
}

FSCS::FSCS(FSCS&& that) : FSCS(IOMaps(that.switches, that.sensors, that.pumps)) {
    swap(*this, that);
}

void FSCS::update() {}