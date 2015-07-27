//
// Created by ami on 25/07/15.
//

#include "Profile.h"
#include "fstream"
#include "fscs/Sensors/PHSensor.h"
#include "fscs/Sensors/TempSensor.h"
#include "fscs/Sensors/WetTraySensor.h"
#include "fscs/Sensors/ECSensor.h"
#include "Controller.h"
#include <sstream>
#include <iostream>

Profile::Profile(char *filename, std::function<void (Routine*)> addRoutine)
        : addRoutine(addRoutine) {
    readProfile(filename);
}

void Profile::checkReading(std::string name, float reading) {}

void Profile::readProfile(char filename[]) {
    std::ifstream file;
    file.open(filename);
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line))
        lines.push_back(line);
    for (std::string &l : lines) {
        std::unordered_map<std::string, std::string> attrs;
        std::istringstream linestream(l);
        std::string pair;
        std::vector<std::string> pairs;
        while (std::getline(linestream, pair, ','))
            pairs.push_back(pair);
        for (std::string p : pairs) {
            std::istringstream pairstream(p);
            std::string keyvalue[2];
            for (int i = 0; i != 2; i++)
                std::getline(pairstream, keyvalue[i], ':');
            attrs.insert(std::make_pair(keyvalue[0], keyvalue[1]));
        }
        if (attrs["type"] == "pump") {
            pumpinfo.insert(std::make_pair(attrs["name"], attrs));
        }
        else if (attrs["type"] == "routine") {

        }
        else if (attrs["type"] == "sensor")
            sensorinfo.insert(std::make_pair(attrs["name"], attrs));
    }
}

std::unordered_map<std::string, Sensor*> Profile::makeSensors() {
    std::unordered_map<std::string, Sensor*> sensors;
    for (auto pair : sensorinfo) {
        std::string subtype = pair.second["subtype"];
        if (subtype == "flow")
            sensors.insert(std::make_pair(pair.first, new Flowmeter(pair.second)));
        else if (subtype == "ph")
            sensors.insert(std::make_pair(pair.first, new PHSensor(pair.second)));
        else if (subtype == "temp")
            sensors.insert(std::make_pair(pair.first, new TempSensor(pair.second)));
        else if (subtype == "wettray")
            sensors.insert(std::make_pair(pair.first, new WetTraySensor(pair.second)));
        else if (subtype == "ec")
            sensors.insert(std::make_pair(pair.first, new ECSensor(pair.second)));
    }
    return sensors;
}

std::unordered_map<std::string, Pump*> Profile::makePumps(std::unordered_map<std::string, Flowmeter*> flowmeters) {
    std::unordered_map<std::string, Pump*> pumps;
    for (auto pair : pumpinfo) {
        try {
            Flowmeter *flowmeter = flowmeters.at("fm" + pair.first);
            pumps.insert(std::make_pair(pair.first, new Pump(pair.second, flowmeter)));
        }
        catch (std::out_of_range oorex) {
            std::cout << pair.first << " has no associated flowmeter" << std::endl;
            pumps.insert(std::make_pair(pair.first, new Pump(pair.second)));
        }
    }
    return pumps;
}
