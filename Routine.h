//
// Created by ami on 22/07/15.
//

#ifndef FSCSMOCK_ROUTINE_H
#define FSCSMOCK_ROUTINE_H

#include <memory>
#include <vector>
#include "Pump.h"
#include <unordered_map>

class Routine {
public:
    Routine();
    Routine(std::unordered_map<std::string, Pump*> syspumps, int priority, std::string name);
    virtual void start() =0;
    bool acquirePumps(std::unordered_map<std::string, Pump*> &syspumps);
    void sendMessage();

    bool operator < (const Routine& r) const {
        return (priority < r.priority);
    }

protected:
    int priority = 3;
    std::string name;

private:
    void releasePumps();
    std::unordered_map<std::string, Pump*> pumps;
};

#endif //FSCSMOCK_ROUTINE_H
