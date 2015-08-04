//
// Created by ami on 25/07/15.
//

#ifndef FSCSMOCK_PROFILE_H
#define FSCSMOCK_PROFILE_H

#include <string>
#include <unordered_map>
#include "Pump.h"
#include "Switch.h"
#include "Machine.h"


class Profile {
public:
    Profile(char filename[]);
    char* getFilename();
    IOMaps makeResources();

private:
    char* filename;
    void readProfile(char filename[]);
    std::unordered_map<std::string, std::shared_ptr<Switch>> makeSwitches();
    //std::unordered_map<std::string, std::shared_ptr<Sensor>> makeSensors();
    std::unordered_map<std::string, std::shared_ptr<Pump>> makePumps(std::unordered_map<std::string, std::shared_ptr<Flowmeter>> sensors);
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> switchinfo;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> pumpinfo;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> sensorinfo;
};

#endif //FSCSMOCK_PROFILE_H
