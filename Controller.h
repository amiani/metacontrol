//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_CONTROLLER_H
#define FSCSMOCK_CONTROLLER_H

#include "Pump.h"
#include "LevelSwitch.h"
#include "Routine.h"
#include "Profile.h"
#include "fscs/Profiles/DefaultProfile.h"
#include "State.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <ctime>

class Controller {
public:
    Controller();
    std::unordered_map<std::string, Flowmeter*> getFlowmeters();

private:
    void start();
    void checkSwitches();
    bool runswitch = false;
    Profile* profile;
    std::time_t clock = std::time(nullptr);
    std::unordered_map<std::string, Pump*> pumps;
    std::unordered_map<std::string, Sensor*> sensors;
    std::unordered_map<std::string, Switch*> switches;
    void addRoutine(Routine*);
    std::vector<Routine*> routines;
    State* state;
};

#endif //FSCSMOCK_CONTROLLER_H