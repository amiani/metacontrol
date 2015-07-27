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
    Routine(int priority, std::string name, std::vector<std::string> pumpnames)
            : priority(priority), name(name), pumpnames(pumpnames) {}
    bool start();
    bool acquirePumps(std::unordered_map<std::string, Pump*> syspumps);
    virtual void sendMessage();

    bool operator < (const Routine& r) const {
        return (priority < r.priority);
    }

protected:
    int priority = 3;
    std::string name;
    virtual void run()=0;

private:
    bool checkPumps();
    void lockPumps();
    void releasePumps();
    std::vector<std::string> pumpnames;
    std::vector<Pump*> pumps;
};

#endif //FSCSMOCK_ROUTINE_H
