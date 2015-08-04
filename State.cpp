//
// Created by ami on 30/07/15.
//

#include "State.h"

State::State(std::weak_ptr<Machine> machine) : machine(machine) {
    enter();
}
