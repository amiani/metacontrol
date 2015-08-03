//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_PROFILE_H
#define FSCSMOCK_PROFILE_H

#include <string>
#include <unordered_map>
#include "Pump.h"
#include "Routine.h"
#include "Profile.h"
#include "Switch.h"


class Profile {
public:
    //Profile(char filename[], std::function<void (Routine*)> addRoutine);
    Profile(char filename[]);
    std::vector<Switch*> makeSwitches();
    std::vector<Sensor*> makeSensors();
    std::vector<Pump*> makePumps(std::unordered_map<std::string, Flowmeter*> sensors);
    //std::unordered_map<std::string, Routine*> getRoutines();

private:
    void readProfile(char filename[]);
    //std::function<void (Routine*)> addRoutine;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> switchinfo;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> pumpinfo;
    //std::unordered_map<std::string, Pump*>* pumps;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> sensorinfo;
    //std::unordered_map<std::string, Sensor*>* sensors;
};

#endif //FSCSMOCK_PROFILE_H
