//
// Created by ami on 02/08/15.
//

#include "Machine.h"

Machine::Machine(const Machine& that)
        : state(that.state),    //this doesn't work yet
          switches(that.switches.size()),
          sensors(that.sensors.size()),
          pumps(that.pumps.size()) {
    for (auto pair : that.switches)
        switches[pair.first] = pair.second;
    for (auto pair : that.sensors)
        sensors[pair.first] = pair.second;
    for (auto pair : that.pumps)
        pumps[pair.first] = pair.second;
}

Machine& Machine::operator=(Machine that) {
    swap(*this, that);
    return *this;
}

Machine::~Machine() {
    delete state;
    for (auto pair : switches)
        delete pair.second;
    switches.clear();
    for (auto pair : sensors)
        delete pair.second;
    sensors.clear();
    for (auto pair : pumps)
        delete pair.second;
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

Switch* Machine::getSwitch(std::string name) {
    return switches[name];
}

Sensor* Machine::getSensor(std::string name) {
    return sensors[name];
}

Pump* Machine::getPump(std::string name) {
    return pumps[name];
}