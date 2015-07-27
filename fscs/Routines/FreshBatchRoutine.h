//
// Created by ami on 23/07/15.
//

#ifndef FSCSMOCK_BATCHROUTINE_H
#define FSCSMOCK_BATCHROUTINE_H


#include "../../Routine.h"

class FreshBatchRoutine : public Routine {
public:
    FreshBatchRoutine(int priority, std::string name, std::vector<std::string> pumpnames, int target)
            : Routine(priority, name, pumpnames), target(target) {}
private:
    void run();
    int target;
};


#endif //FSCSMOCK_BATCHROUTINE_H
