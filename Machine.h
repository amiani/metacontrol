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
    Machine(State* state, Resources r)
            : state(state), switches(r.switches), sensors(r.sensors), pumps(r.pumps) {};
    Machine(const Machine&);
    Machine& operator=(Machine);

    std::shared_ptr<Switch> getSwitch(std::string);
    std::shared_ptr<Sensor> getSensor(std::string);
    std::shared_ptr<Pump> getPump(std::string);

    virtual void update()=0;

protected:
    friend class State;
    std::unique_ptr<State> state;
    std::unordered_map<std::string, std::shared_ptr<Switch>> switches;
    std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors;
    std::unordered_map<std::string, std::shared_ptr<Pump>> pumps;

private:
    void swap(Machine& first, Machine& second);
};

struct Resources {
    std::unordered_map<std::string, std::shared_ptr<Switch>> switches;
    std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors;
    std::unordered_map<std::string, std::shared_ptr<Pump>> pumps;
};

#endif //METACONTROL_MACHINE_H
