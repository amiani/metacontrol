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
    ~Controller();

    std::unordered_map<std::string, Flowmeter*> getFlowmeters();

private:
    void start();
    void checkSwitches();
    void checkSensors();
    bool runswitch = false;
    Profile* profile;
    Machine* machine;
    std::time_t clock = std::time(nullptr);
    //void addRoutine(Routine*);
    //std::vector<Routine*> routines;
};

#endif //FSCSMOCK_CONTROLLER_H