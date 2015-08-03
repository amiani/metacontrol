//
// Created by ami on 25/07/15.
//

#include "Controller.h"
#include "fscs/FSCS.h"

Controller::Controller() {
    //std::function<void(Routine*)> ar = [this](Routine* r){ addRoutine(r); };
    profile = new Profile("testprofile.txt");
    machine = new FSCS(profile->makeSwitches(), profile->makeSensors(), profile->makePumps(getFlowmeters()));
    start();
}

Controller::Controller(const Controller& that) {
    delete profile;
    delete machine;
    profile = that.profile;
    machine = that.machine;
}

Controller::~Controller() {
    delete profile;
    delete machine;
}

void Controller::start() {
    while (runswitch) {
        machine->update();
        //read keypad
        //display LCD
    }
}

/**void Controller::checkSwitches() {
    for (auto &s : switches) {
        bool state = s->isUp();
        profile->checkReading(s.first, state);
    }
}**/

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