//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_STATE_H
#define METACONTROLSIM_STATE_H


#include "Machine.h"

class State {
public:
    State(Machine* machine) : machine(machine) {}
    virtual void update()=0;

private:
    Machine* machine;
};


#endif //METACONTROLSIM_STATE_H
