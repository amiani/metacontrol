//
// Created by ami on 22/07/15.
//

#include <iostream>
#include "Routine.h"

Routine::Routine(std::unordered_map<std::string, Pump*> syspumps, int priority, std::string name)
        : priority(priority), name(name){
    for (auto &p : pumps) {
        if (syspumps[p.first])
            p.second = syspumps[p.first];
        else
            std::cout << "No such pump." << std::endl;
    }
}
bool Routine::acquirePumps(std::unordered_map<std::string, Pump*> &syspumps) {
    for (auto &p : pumps) {
        if (p.second->lock())
            return false;
    }
    return true;
}