//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_CONTROLLER_H
#define FSCSMOCK_CONTROLLER_H

#include "Profile.h"
#include "Machine.h"
#include <vector>
#include <time.h>

class Controller {
public:
    Controller();
    Controller(const Controller&);

private:
    void start();
    bool runswitch = false;
    std::unique_ptr<Profile> profile;
    std::shared_ptr<Machine> machine;
    static time_t myclock;
};

//time_t Controller::myclock = time(nullptr);

#endif //FSCSMOCK_CONTROLLER_H