//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_CONTROLLER_H
#define FSCSMOCK_CONTROLLER_H

#include "Pump.h"
#include "LevelSensor.h"
#include "Routine.h"
#include "Profile.h"
#include "fscs/Profiles/DefaultProfile.h"
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
    void checkSensors();
    bool runswitch = false;
    Profile* profile;
    std::time_t clock = std::time(nullptr);
    std::unordered_map<std::string, Pump*> pumps;
    std::unordered_map<std::string, Sensor*> sensors;
    void addRoutine(Routine*);
    std::vector<Routine*> routines;
};

#endif //FSCSMOCK_CONTROLLER_H