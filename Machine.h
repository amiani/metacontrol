//
// Created by ami on 02/08/15.
//

#ifndef METACONTROL_MACHINE_H
#define METACONTROL_MACHINE_H

#include <unordered_map>
#include "Switch.h"
#include "Sensor.h"
#include "Pump.h"
#include "State.h"

class State;

class Machine {
public:
    Machine(State* state, std::unordered_map<std::string, Switch*> switches, std::unordered_map<std::string, Sensor*> sensor, std::unordered_map<std::string, Pump*> pumps)
            : state(state), switches(switches), sensors(sensors), pumps(pumps) {};
    Machine(const Machine&);
    Machine& operator=(Machine);
    virtual ~Machine();

    Switch* getSwitch(std::string);
    Sensor* getSensor(std::string);
    Pump* getPump(std::string);

    virtual void update();

protected:
    friend class State;
    State* state;
    std::unordered_map<std::string, Switch*> switches;
    std::unordered_map<std::string, Sensor*> sensors;
    std::unordered_map<std::string, Pump*> pumps;

private:
    void swap(Machine& first, Machine& second);
};


#endif //METACONTROL_MACHINE_H
