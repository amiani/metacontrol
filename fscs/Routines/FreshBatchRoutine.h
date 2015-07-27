//
// Created by ami on 23/07/15.
//

#ifndef FSCSMOCK_BATCHROUTINE_H
#define FSCSMOCK_BATCHROUTINE_H


#include "../../Routine.h"

class FreshBatchRoutine : public Routine {
public:
    FreshBatchRoutine(std::unordered_map<std::string, Pump*> syspumps, std::string name)
            : Routine(syspumps, 0, name) {}
private:
    void run();
    int target;
};


#endif //FSCSMOCK_BATCHROUTINE_H
