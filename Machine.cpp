//
// Created by ami on 02/08/15.
//

#include "Machine.h"

Machine::Machine(const Machine& that)
        : state(that.state),    //this doesn't work yet
          switches(that.switches.size()),
          sensors(that.sensors.size()),
          pumps(that.pumps.size()) {
    for (int i = 0; i != switches.size(); i++)
        this->switches[i] = that.switches[i];
    for (int i = 0; i != sensors.size(); i++)
        this->sensors[i] = that.sensors[i];
    for (int i = 0; i != pumps.size(); i++)
        this->pumps[i] = that.pumps[i];
}

Machine& Machine::operator=(Machine that) {
    swap(*this, that);
    return *this;
}

Machine::~Machine() {
    delete state;
    for (Switch* s : switches)
        delete s;
    switches.clear();
    for (Sensor* s : sensors)
        delete s;
    sensors.clear();
    for (Pump* p : pumps)
        delete p;
    pumps.clear();
}

void Machine::swap(Machine& first, Machine& second) {
    using std::swap;
    swap(first.state, second.state);
    swap(first.switches, second.switches);
    swap(first.sensors, second.sensors);
    swap(first.pumps, second.pumps);
}

void Machine::update() {
    state->update();
}
