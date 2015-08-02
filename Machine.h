//
// Created by ami on 02/08/15.
//

#ifndef METACONTROL_MACHINE_H
#define METACONTROL_MACHINE_H


#include "State.h"

class Machine {
public:
    virtual Machine()=0;
    void update() { state->update(); }

protected:
    State* state;
};


#endif //METACONTROL_MACHINE_H
