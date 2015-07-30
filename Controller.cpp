//
// Created by ami on 25/07/15.
//

#include "Controller.h"
#include <algorithm>

Controller::Controller() {
    std::function<void(Routine*)> ar = [this](Routine* r){ addRoutine(r); };
    profile = new Profile("testprofile.txt", ar);
    sensors = profile->makeSensors();
    pumps = profile->makePumps(getFlowmeters());

    start();
}

void Controller::start() {
    while (runswitch) {
        checkSwitches();
        profile->checkTime(std::gmtime(&clock));
        state->update();
        for (auto &p : pumps)
            p.second->update();
    }
}

void Controller::checkSwitches() {
    for (auto &s : switches) {
        bool state = s.second->isUp();
        profile->checkReading(s.first, state);
    }
}

void Controller::addRoutine(Routine* r) {
    r->acquirePumps(pumps);
    routines.push_back(r);
    std::sort(routines.begin(), routines.end());
}

std::unordered_map<std::string, Flowmeter*> Controller::getFlowmeters() {
    std::unordered_map<std::string, Flowmeter*> flowmeters;
    for (auto sensor : sensors) {
        Flowmeter* s = dynamic_cast<Flowmeter*>(sensor.second);
        if (s)
            flowmeters.insert(std::make_pair(sensor.first, s));
    }
    return flowmeters;
}