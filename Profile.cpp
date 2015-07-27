//
// Created by ami on 23/07/15.
//

#include "Profile.h"
#include "fstream"
#include "fscs/Sensors/PHSensor.h"
#include "fscs/Sensors/TempSensor.h"
#include "fscs/Sensors/WetTraySensor.h"
#include "fscs/Sensors/ECSensor.h"
#include "Controller.h"
#include <sstream>

Profile::Profile(char *filename, std::function<void(const Routine *)> addRoutine) : addRoutine(addRoutine) {
    readProfile(filename);
}

void Profile::readProfile(char filename[]) {
    std::ifstream file;
    file.open(filename);
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line))
        lines.push_back(line);
    for (std::string line : lines) {
        std::unordered_map<std::string, std::string> attrs;
        std::istringstream linestream(line);
        std::string pair;
        std::vector<std::string> pairs;
        while (std::getline(linestream, pair, ','))
            pairs.push_back(pair);
        for (std::string pair : pairs) {
            std::istringstream pairstream(pair);
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
        else if (attrs["type"] == "sensor") {
            sensorinfo.insert(std::make_pair(attrs["name"], attrs));
        }
    }
}

std::unordered_map<std::string, Pump*> Profile::makePumps() {
    std::unordered_map<std::string, Pump*> tpumps;
    for (auto pair : pumpinfo)
        tpumps.insert(std::make_pair(pair.first, new Pump(pair.second)));
    pumps = &tpumps;
    return tpumps;
}

std::unordered_map<std::string, Sensor*> Profile::makeSensors() {
    std::unordered_map<std::string, Sensor*> tsensors;
    for (auto pair : sensorinfo) {
        std::string subtype = pair.second["subtype"];
        if (subtype == "flow")
            tsensors.insert(std::make_pair(pair.first, new FlowMeter(pair.second)));
        else if (subtype == "ph")
            tsensors.insert(std::make_pair(pair.first, new PHSensor(pair.second)));
        else if (subtype == "temp")
            tsensors.insert(std::make_pair(pair.first, new TempSensor(pair.second)));
        else if (subtype == "wettray")
           tsensors.insert(std::make_pair(pair.first, new WetTraySensor(pair.second)));
        else if (subtype == "ec")
            tsensors.insert(std::make_pair(pair.first, new ECSensor(pair.second)));
    }
    sensors = &tsensors;
    return tsensors;
}

