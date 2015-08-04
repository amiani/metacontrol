//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_CONTROLLER_H
#define FSCSMOCK_CONTROLLER_H

#include "Profile.h"
#include "Machine.h"
#include <vector>
#include <ctime>

class Controller {
public:
    Controller();
    Controller(const Controller&);

    //std::unordered_map<std::string, Flowmeter*> getFlowmeters();

private:
    void start();
    void checkSwitches();
    void checkSensors();
    bool runswitch = false;
    std::unique_ptr<Profile> profile;
    std::shared_ptr<Machine> machine;
    static std::time_t clock;
    //void addRoutine(Routine*);
    //std::vector<Routine*> routines;
};

std::time_t Controller::clock = std::time(nullptr);
#endif //FSCSMOCK_CONTROLLER_H