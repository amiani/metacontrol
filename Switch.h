//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_SWITCH_H
#define METACONTROLSIM_SWITCH_H

#include <string>
#include <unordered_map>

class Switch {
public:
    Switch(std::unordered_map<std::string, std::string> attrs) : attributes(attrs) {
        name = attributes.at("name");
    }
    bool isUp() const { return state; }
    std::string getName() { return name; }

private:
    bool state = false;
    std::unordered_map<std::string, std::string> attributes;
    std::string name;
};


#endif //METACONTROLSIM_SWITCH_H
