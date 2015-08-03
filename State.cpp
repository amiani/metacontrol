//
// Created by ami on 30/07/15.
//

#include "State.h"

State::~State() {
    delete machine;
}

void State::changeState(State* newstate) {
    machine->state = newstate;
}
