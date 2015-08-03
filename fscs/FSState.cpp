//
// Created by ami on 30/07/15.
//

#include "FSState.h"

bool FSState::isRunSwitchOn() {
    machine->getSwitch("RUNSWITCH")->isUp();
}

bool FSState::isMixHigh() {
    return machine->LS5->isUp();
}

void OffState::update() {
    if (isRunSwitchOn()) {
        if (isMixHigh())
            changeState(StandbyState::enter());
        else
            changeState(FastFillState::enter());
    }
}

FastFillState* FastFillState::enter() {
    //start pumps
    return &instance;
}

void FastFillState::update() {
    if (isMixHigh()) {
        //stop pumps
        changeState(StandbyState::enter());
    }
}

void StandbyState::sampleTimer() {
    changeState(SampleState::enter());
}

void StandbyState::referenceTimer() {
    changeState(ReferenceState::enter());
}

void StandbyState::turnOff() {
    changeState(OffState::enter());
}

BatchState* BatchState::enter() {
    //start pump
    return &instance;
}

void BatchState::update() {
    //monitor sensors
    //control pumps
    //check if finished then
    /** if (fscs->isMixHigh)
     *      changeState(SampleState::enter());
     *  else
     *      changeState(BatchState::enter()); **/
}

SampleState* SampleState::enter() {
    //start pump
    return &instance;
}

void SampleState::update() {
    /** if (finished)
     *      if (EC is ok)
     *          changeState(StandbyState::enter());
     *      else
     *          changeState(RefreshState::enter());**/
}

RefreshState* RefreshState::enter() {
    //start pumps
    return &instance;
}

void RefreshState::update() {
    /** if (finished)
     *      changeState(StandbyState::enter());**/
}

ReferenceState* ReferenceState::enter() {
    //start pumps
    return &instance;
}


