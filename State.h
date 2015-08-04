//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_STATE_H
#define METACONTROLSIM_STATE_H


#include "Machine.h"

class Machine;

class State {
public:
    State(Machine* machine) : machine(machine) {}

    virtual void update()=0;

protected:
    virtual void changeState(State* newstate);
    std::shared_ptr<Machine> machine;
};


#endif //METACONTROLSIM_STATE_H
