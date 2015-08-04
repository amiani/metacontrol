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

struct IOMaps {
    std::unordered_map<std::string, std::shared_ptr<Switch>> switches;
    std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors;
    std::unordered_map<std::string, std::shared_ptr<Pump>> pumps;
};

class Machine {
public:
    Machine(std::unique_ptr<State> state, IOMaps r)
            : state(std::move(state)), switches(r.switches), sensors(r.sensors), pumps(r.pumps) {};
    //Machine(const Machine&);

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

#endif //METACONTROL_MACHINE_H
