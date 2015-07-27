//
// Created by ami on 27/07/15.
//

#ifndef METACONTROLSIM_TESTPUMP_H
#define METACONTROLSIM_TESTPUMP_H


#include <unordered_map>
#include "Pump.h"
#include "Flowmeter.h"

class TestPump : public Pump {
public:
    TestPump(std::unordered_map<std::string, std::string> attrs, Flowmeter* fm) : Pump(attrs, fm) {}


};


#endif //METACONTROLSIM_TESTPUMP_H
