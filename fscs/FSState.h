//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_FSSTATE_H
#define METACONTROLSIM_FSSTATE_H

#include "../State.h"
#include "FSCS.h"

class FSCS;

class FSState : public State {
public:
    FSState(std::weak_ptr<FSCS> fscs);

protected:
    //void changeState(std::unique_ptr<FSState> newstate);
    bool isRunSwitchOn();
    bool isMixHigh();
    bool isSampletime();
    bool isReferencetime();
    int timeinstate = 0;
    float getEC();
    std::shared_ptr<FSCS> machine;
};

class OffState : public FSState {
public:
    OffState(std::weak_ptr<FSCS> fscs) : FSState(fscs) {}
    void enter();
    void update();

private:
};

class FastFillState : public FSState {
public:
    FastFillState(std::weak_ptr<FSCS> fscs) : FSState(fscs) {}
    void enter();
    void update();
};

class StandbyState : public FSState {
public:
    StandbyState(std::weak_ptr<FSCS> fscs) : FSState(fscs) {}
    void enter();
    void update() {}
    void sampleTimer();
    void referenceTimer();
    void turnOff();
};

class BatchState : public FSState {
public:
    BatchState(std::weak_ptr<FSCS> fscs) : FSState(fscs) {}
    void enter();
    void update();
};

class SampleState : public FSState {
public:
    SampleState(std::weak_ptr<FSCS> fscs) : FSState(fscs) {}
    void enter();
    void update();
};

class RefreshState : public FSState {
public:
    RefreshState(std::weak_ptr<FSCS> fscs) : FSState(fscs) {}
    void enter();
    void update();
};

class ReferenceState : public FSState {
public:
    ReferenceState(std::weak_ptr<FSCS> fscs) : FSState(fscs) {}
    void enter();
    void update();
};

#endif //METACONTROLSIM_FSSTATE_H