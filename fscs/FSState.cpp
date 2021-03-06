//
// Created by ami on 30/07/15.
//

#include "FSState.h"

FSState::FSState(std::shared_ptr<Machine> machine)
        : State(machine), fscs(std::dynamic_pointer_cast<FSCS>(machine)) {}

/**void FSState::changeState(std::unique_ptr<FSState> newstate) {
    changeState(newstate);
}**/

bool FSState::isRunSwitchOn() const {
    return fscs->getSwitch("runswitch")->isUp();
}

bool FSState::isMixHigh() const {
    return fscs->LS5->isUp();
}

void OffState::update() {
    if (isRunSwitchOn()) {
        if (isMixHigh())
            changeState<StandbyState>();
        else
            changeState<FastFillState>();
    }
}

void FastFillState::enter() {
    //start pumps
}

void FastFillState::update() {
    if (isMixHigh()) {
        //stop pumps
        changeState<StandbyState>();
    }
}

void StandbyState::sampleTimer() {
    changeState<SampleState>();
}

void StandbyState::referenceTimer() {
    changeState<ReferenceState>();
}

void StandbyState::turnOff() {
    changeState<OffState>();
}

void BatchState::enter() {
    //start pump
}

void BatchState::update() {
    //monitor sensors
    //control pumps
    //check if finished then
    /** if (fscs->isMixHigh)
     *      changeState<SampleState>();
     *  else
     *      changeState<BatchState>();**/
}

void SampleState::enter() {
    //start pump
}

void SampleState::update() {
    /** if (finished)
     *      if (EC is ok)
     *          changeState<StandbyState>();
     *      else
     *          changeState<RefreshState>();**/
}

void RefreshState::enter() {
    //start pumps
}

void RefreshState::update() {
    /** if (finished)
     *      changeState<StandbyState>();
}

ReferenceState* ReferenceState::enter() {
    //start pumps
    return &instance;**/
}