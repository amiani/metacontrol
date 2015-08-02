//
// Created by ami on 25/07/15.
//

#include "Controller.h"
#include <algorithm>
#include "fscs/FSCS.h"

Controller::Controller() {
    //std::function<void(Routine*)> ar = [this](Routine* r){ addRoutine(r); };
    profile = new Profile("testprofile.txt");
    sensors = profile->makeSensors();
    pumps = profile->makePumps(getFlowmeters());
    machine = new FSCS();

    start();
}

void Controller::start() {
    while (runswitch) {
        checkSwitches();
        checkSensors();
        machine->update();
        for (auto &p : pumps)
            p->update();
    }
}

void Controller::checkSwitches() {
    for (auto &s : switches) {
        bool state = s->isUp();
        profile->checkReading(s.first, state);
    }
}

/**void Controller::addRoutine(Routine* r) {
    r->acquirePumps(pumps);
    routines.push_back(r);
    std::sort(routines.begin(), routines.end());
}**/

std::unordered_map<std::string, Flowmeter*> Controller::getFlowmeters() {
    std::unordered_map<std::string, Flowmeter*> flowmeters;
    for (auto sensor : sensors) {
        Flowmeter* s = dynamic_cast<Flowmeter*>(sensor);
        if (s)
            flowmeters.insert(std::make_pair(s->getName(), s));
    }
    return flowmeters;
}