//
// Created by ami on 7/26/15.
//
#include "Sensor.h"

Sensor::Sensor(std::unordered_map <std::string, std::string> attrs) {
    name = attrs["name"];
    port = attrs["port"];
}