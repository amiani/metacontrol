//
// Created by ami on 25/07/15.
//

#include "Controller.h"
#include "fscs/FSCS.h"

Controller::Controller() {
    //std::function<void(Routine*)> ar = [this](Routine* r){ addRoutine(r); };
    profile = std::unique_ptr<Profile>(new Profile("testprofile.txt"));
    machine = std::make_shared<FSCS>(FSCS(profile->makeResources()));
    start();
}

Controller::Controller(const Controller& that) {
    profile = std::unique_ptr<Profile>(new Profile(that.profile->getFilename()));
    machine = that.machine;
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

/**std::unordered_map<std::string, Flowmeter*> Controller::getFlowmeters() {
    std::unordered_map<std::string, Flowmeter*> flowmeters;
    for (auto sensor : sensors) {
        Flowmeter* s = dynamic_cast<Flowmeter*>(sensor);
        if (s)
            flowmeters.insert(std::make_pair(s->getName(), s));
    }
    return flowmeters;
}**/