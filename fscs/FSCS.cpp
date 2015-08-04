//
// Created by ami on 04/08/15.
//

#include "FSCS.h"

FSCS::FSCS(IOMaps r) : Machine(std::unique_ptr<OffState>(new OffState(this)), r) {
    LS5 = switches["LS5"];
}

void FSCS::update() {}