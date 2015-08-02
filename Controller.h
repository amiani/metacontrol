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
#include "Machine.h"
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
    void checkSensors();
    bool runswitch = false;
    Profile* profile;
    Machine* machine;
    std::time_t clock = std::time(nullptr);
    std::vector<Pump*> pumps;
    std::vector<Sensor*> sensors;
    std::vector<Switch*> switches;
    void addRoutine(Routine*);
    std::vector<Routine*> routines;
};

#endif //FSCSMOCK_CONTROLLER_H