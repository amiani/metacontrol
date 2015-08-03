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
    FSState(FSCS* fscs) : State(fscs), machine(fscs) {}

protected:
    void changeState(FSState* newstate);
    bool isRunSwitchOn();
    bool isMixHigh();
    bool isSampletime();
    bool isReferencetime();
    int timeinstate = 0;
    float getEC();
    FSCS* machine;
};

class OffState : public FSState {
public:
    OffState(FSCS* fscs) : FSState(fscs) {}
    static OffState* enter() { return &instance; }
    void update();

private:
    static OffState instance;
};

class FastFillState : public FSState {
public:
    FastFillState(FSCS* fscs) : FSState(fscs) {}
    static FastFillState* enter();
    void update();

private:
    static FastFillState instance;

};

class StandbyState : public FSState {
public:
    StandbyState(FSCS* fscs) : FSState(fscs) {}
    static StandbyState* enter() { return &instance; }
    void update() {}
    void sampleTimer();
    void referenceTimer();
    void turnOff();

protected:
    static StandbyState instance;
};

class BatchState : public FSState {
public:
    BatchState(FSCS* fscs) : FSState(fscs) {}
    static BatchState* enter();
    void update();

private:
    static BatchState instance;
};

class SampleState : public FSState {
public:
    SampleState(FSCS* fscs) : FSState(fscs) {}
    static SampleState* enter();
    void update();

private:
    static SampleState instance;
};

class RefreshState : public FSState {
public:
    RefreshState(FSCS* fscs) : FSState(fscs) {}
    static RefreshState* enter();
    void update();

private:
    static RefreshState instance;
};

class ReferenceState : public FSState {
public:
    ReferenceState(FSCS* fscs) : FSState(fscs) {}
    static ReferenceState* enter();
    void update();

private:
    static ReferenceState instance;
};

#endif //METACONTROLSIM_FSSTATE_H
