//
// Created by ami on 22/07/15.
//

#ifndef FSCSMOCK_CONTROLLER_H
#define FSCSMOCK_CONTROLLER_H

#include "Pump.h"
#include "LevelSensor.h"
#include "Routine.h"
#include "Profile.h"
#include "FSCS/Profiles/DefaultProfile.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <ctime>

class Controller {
public:
    Controller();

private:
    bool init();
    void readProfile(char file[]);  //this method will likely end up in an initializer class
    void start();
    void checkSensors();
    bool runswitch = false;
    Profile profile;
    std::time_t clock = std::time(nullptr);
    std::unordered_map<std::string, Pump*> pumps;
    std::unordered_map<std::string, Sensor*> sensors;
    std::vector<Routine*> routines;
};


#endif //FSCSMOCK_CONTROLLER_H
