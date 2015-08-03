//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_SWITCH_H
#define METACONTROLSIM_SWITCH_H


class Switch {
public:
    bool isUp() const { return state; }
    std::string getName() { return name; }

private:
    bool state = false;
    std::string name;
};


#endif //METACONTROLSIM_SWITCH_H
