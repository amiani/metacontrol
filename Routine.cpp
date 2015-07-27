//
// Created by ami on 25/07/15.
//

#include <iostream>
#include "Routine.h"

bool Routine::start() {
    std::cout << "starting " << name << " routine" << std::endl;
    if (checkPumps()) {
        lockPumps();
        run();
        releasePumps();
        sendMessage();
        return true;
    }
    else {
        std::cout << name << " routine couldn't acquire pumps" << std::endl;
        return false;
    }
}

bool Routine::checkPumps() {
    for (auto p : pumps) {
        if (p->isLocked())
            return false;
    }
    return true;
}

bool Routine::acquirePumps(std::unordered_map<std::string, Pump*> syspumps) {
    try {
        for (auto pname : pumpnames)
            pumps.push_back(syspumps.at(pname));
        return true;
    }
    catch (std::out_of_range ofrex) {
        return false;
    }
}

void Routine::lockPumps() {
    for (auto p : pumps)
        p->lock();
}

void Routine::releasePumps() {
    for (auto p : pumps)
        p->unlock();
}

void Routine::sendMessage() { }