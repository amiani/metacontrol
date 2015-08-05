//
// Created by ami on 02/08/15.
//

#ifndef METACONTROL_MACHINE_H
#define METACONTROL_MACHINE_H

#include <unordered_map>
#include "Switch.h"
#include "Sensor.h"
#include "Pump.h"

class State;

struct IOMaps {
    IOMaps() {};
    IOMaps(std::unordered_map<std::string, std::shared_ptr<Switch>> switches,
           std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors,
           std::unordered_map<std::string, std::shared_ptr<Pump>> pumps)
            : switches(switches), sensors(sensors), pumps(pumps) {}

    std::unordered_map<std::string, std::shared_ptr<Switch>> switches;
    std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors;
    std::unordered_map<std::string, std::shared_ptr<Pump>> pumps;
};

class Machine : public std::enable_shared_from_this<Machine> {
public:
    Machine(std::unique_ptr<State> state, IOMaps r);
    Machine(const Machine&) = delete;

    std::shared_ptr<Switch> getSwitch(std::string);
    std::shared_ptr<Sensor> getSensor(std::string);
    std::shared_ptr<Pump> getPump(std::string);

    virtual void update()=0;

    std::shared_ptr<Machine> getThis();

protected:
    friend class State;
    std::unique_ptr<State> state;
    std::unordered_map<std::string, std::shared_ptr<Switch>> switches;
    std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors;
    std::unordered_map<std::string, std::shared_ptr<Pump>> pumps;

    void swap(Machine& first, Machine& second);
};

#endif //METACONTROL_MACHINE_H
