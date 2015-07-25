//
// Created by ami on 22/07/15.
//

#include "Controller.h"
#include <algorithm>
#include <sstream>
#include <boost/python.hpp>
#include "python3.4m/Python.h"

using namespace boost;

Controller::Controller() {
    if (init())
        start();
}

bool Controller::init() {
    readProfile("/defaultprofile.txt");
}

void Controller::readProfile(char file[]) {
    std::istringstream prflstream(file);
    std::string line;
    std::unordered_map<std::string, std::string> options;
    python::object pyfunc;
    Py_Initialize();
    pyfunc();
    Py_Finalize();

}

void Controller::start() {
    while (runswitch) {
        checkSensors();
        //TODO: thread this so that multiple routines can run simultaneously
        Routine* r = routines.front();
        if (r->acquirePumps(pumps)) {
            routines.erase(routines.begin());
            r->start();
        }
        std::sort(routines.begin(), routines.end());
        profile.checkTime(std::gmtime(&clock));
    }
}

void Controller::checkSensors() {
    for (auto &s : sensors) {
        float reading = s.second->getReading();
        profile.checkReading(s.first, reading);
    }
}