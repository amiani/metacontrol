//
// Created by ami on 27/07/15.
//

#ifndef METACONTROLSIM_TESTFLOWMETER_H
#define METACONTROLSIM_TESTFLOWMETER_H

#include "Flowmeter.h"

class TestFlowmeter : public Flowmeter {
public:
    TestFlowmeter(std::unordered_map<std::string, std::string> attrs) : Flowmeter(attrs) {}
    float getReading() { return 10; }
};
#endif //METACONTROLSIM_TESTFLOWMETER_H
