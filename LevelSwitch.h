//
// Created by ami on 23/07/15.
//

#ifndef FSCSMOCK_LEVELSENSOR_H
#define FSCSMOCK_LEVELSENSOR_H

#include "Switch.h"
#include <string>
#include <unordered_map>

class LevelSwitch : public Switch {
public:
    LevelSwitch(std::unordered_map<std::string, std::string> attrs) : Switch(attrs) {}
private:
    int isup = 0;
};


#endif //FSCSMOCK_LEVELSENSOR_H
