//
// Created by ami on 23/07/15.
//

#include "LevelSensor.h"

LevelSensor::LevelSensor(std::unordered_map<std::string, std::string> attrs) : Sensor(attrs) {

}

float LevelSensor::getReading() {
    return isup;
}