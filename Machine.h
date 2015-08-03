//
// Created by ami on 02/08/15.
//

#ifndef METACONTROL_MACHINE_H
#define METACONTROL_MACHINE_H

#include <vector>
#include "Switch.h"
#include "Sensor.h"
#include "Pump.h"
#include "State.h"

class State;

class Machine {
public:
    Machine(State* state, std::vector<Switch*> switches, std::vector<Sensor*> sensor, std::vector<Pump*> pumps)
            : state(state), switches(switches), sensors(sensors), pumps(pumps) {};
    Machine(const Machine&);
    Machine& operator=(Machine);
    virtual ~Machine();

    virtual void update();

protected:
    friend class State;
    State* state;
    std::vector<Switch*> switches;
    std::vector<Sensor*> sensors;
    std::vector<Pump*> pumps;

private:
    void swap(Machine& first, Machine& second);
};


#endif //METACONTROL_MACHINE_H
