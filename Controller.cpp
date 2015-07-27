//
// Created by ami on 22/07/15.
//

#include "Controller.h"
#include <algorithm>

Controller::Controller() {
    if (init())
        start();
}

bool Controller::init() {
    profile = new Profile("defaultprofile.txt", this->addRoutine);
    pumps = profile->makePumps();
    sensors = profile->makeSensors();
    return true;
}

void Controller::start() {
    while (runswitch) {
        checkSensors();
        //TODO: thread this so that multiple routines can run simultaneously
        Routine* r = routines.front();
        if (r->acquirePumps(pumps)) {
            routines.erase(routines.begin());
            r->start();
            delete r;
        }
        std::sort(routines.begin(), routines.end());
        for (auto pumppair : pumps)
            pumppair.second->update();
        //profile.checkTime(std::gmtime(&clock));
    }
}

void Controller::checkSensors() {
    for (auto &s : sensors) {
        float reading = s.second->getReading();
        profile->checkReading(s.first, reading);
    }
}

void Controller::addRoutine(Routine* r) {
    routines.push_back(r);
    std::sort(routines.begin(), routines.end());
}