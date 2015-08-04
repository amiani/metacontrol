//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_STATE_H
#define METACONTROLSIM_STATE_H


#include "Machine.h"

class Machine;

class State {
public:
    State(std::weak_ptr<Machine> machine);

    virtual void enter()=0;
    virtual void update()=0;

protected:
    template <class T> void changeState();
    std::shared_ptr<Machine> machine;
};

template <class T> void State::changeState() {
    machine->state.reset(new T(machine));
}

#endif //METACONTROLSIM_STATE_H
