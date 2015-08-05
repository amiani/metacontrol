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

Profile::Profile(char filename[]) : filename(filename) {
    readProfile(filename);
}

char* Profile::getFilename() const { return filename; }

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
        else if (attrs["type"] == "switch") {
            switchinfo.insert(std::make_pair(attrs["name"], attrs));
        }
        else if (attrs["type"] == "sensor")
            sensorinfo.insert(std::make_pair(attrs["name"], attrs));
    }
}

std::unordered_map<std::string, std::shared_ptr<Switch>> Profile::makeSwitches() {
    std::unordered_map<std::string, std::shared_ptr<Switch>> switches;
    for (auto pair : switchinfo)
        switches.insert(std::make_pair(pair.first, std::make_shared<Switch>(pair.second)));
    return switches;
}

/**std::unordered_map<std::string, std::shared_ptr<Sensor>> Profile::makeSensors() {
    std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors;
    std::unordered_map<std::string, std::shared_ptr<Flowmeter>> flowmeters;
    for (auto pair : sensorinfo) {
        std::string subtype = pair.second["subtype"];
        if (subtype == "flow") {
            auto flowpair = std::make_pair(pair.first, std::make_shared(Flowmeter(pair.second)));
            sensors.insert(flowpair);
            flowmeters.insert(flowpair);
        }
        else if (subtype == "ph")
            sensors.insert(pair.first, std::make_shared(PHSensor(pair.second)));
        else if (subtype == "temp")
            sensors.insert(pair.first, std::make_shared(TempSensor(pair.second)));
        else if (subtype == "wettray")
            sensors.insert(pair.first, std::make_shared(WetTraySensor(pair.second)));
        else if (subtype == "ec")
            sensors.insert(pair.first, std::make_shared(ECSensor(pair.second)));
    }
    return sensors;
}**/

std::unordered_map<std::string, std::shared_ptr<Pump>> Profile::makePumps(std::unordered_map<std::string, std::shared_ptr<Flowmeter>> flowmeters) {
    std::unordered_map<std::string, std::shared_ptr<Pump>> pumps;
    for (auto pair : pumpinfo) {
        try {
            std::shared_ptr<Flowmeter> flowmeter = flowmeters.at("fm" + pair.first);
            pumps.insert(std::make_pair(pair.first, std::make_shared<Pump>(pair.second, flowmeter)));
        }
        catch (std::out_of_range oorex) {
            std::cout << pair.first << " has no associated flowmeter" << std::endl;
            pumps.insert(std::make_pair(pair.first, std::make_shared<Pump>(pair.second)));
        }
    }
    return pumps;
}

IOMaps Profile::makeResources() {
    IOMaps r;
    std::unordered_map<std::string, std::shared_ptr<Sensor>> sensors;
    std::unordered_map<std::string, std::shared_ptr<Flowmeter>> flowmeters;
    for (auto pair : sensorinfo) {
        std::string subtype = pair.second["subtype"];
        if (subtype == "flow") {
            auto flowpair = std::make_pair(pair.first, std::make_shared<Flowmeter>(pair.second));
            sensors.insert(flowpair);
            flowmeters.insert(flowpair);
        }
        else if (subtype == "ph")
            sensors.insert(std::make_pair(pair.first, std::make_shared<PHSensor>(pair.second)));
        else if (subtype == "temp")
            sensors.insert(std::make_pair(pair.first, std::make_shared<TempSensor>(pair.second)));
        else if (subtype == "wettray")
            sensors.insert(std::make_pair(pair.first, std::make_shared<WetTraySensor>(pair.second)));
        else if (subtype == "ec")
            sensors.insert(std::make_pair(pair.first, std::make_shared<ECSensor>(pair.second)));
    }

    r.switches = makeSwitches();
    r.sensors = sensors;
    r.pumps = makePumps(flowmeters);
}
