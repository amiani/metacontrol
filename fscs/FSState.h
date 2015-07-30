//
// Created by ami on 30/07/15.
//

#ifndef METACONTROLSIM_FSSTATE_H
#define METACONTROLSIM_FSSTATE_H


#include "../State.h"
#include "FSCS.h"

class FSState : public State {
public:
    virtual void turnOn() {};
    virtual void mixLow() {};
    virtual void mixHigh() {};
    virtual void sampleTimer();
    virtual void referenceTimer();
    virtual void turnOff();

protected:
    FSCS* fscs;
    void changeState(FSState* newstate);
    bool isSampletime();
    bool isReferencetime();
    float getEC();
};

class OffState : public FSState {
public:
    static OffState* enter() { return &instance; }
    void update() {}
    void turnOn();

private:
    static OffState instance;
};

class FastFillState : public FSState {
public:
    static FastFillState* enter();
    void update();

private:
    static FastFillState instance;

};

class StandbyState : public FSState {
public:
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
    static BatchState* enter();
    void update();

private:
    static BatchState instance;
};

class SampleState : public FSState {
public:
    static SampleState* enter();
    void update();

private:
    static SampleState instance;
};

class RefreshState : public FSState {
public:
    static RefreshState* enter();
    void update();

private:
    static RefreshState instance;
};

class ReferenceState : public FSState {
public:
    static ReferenceState* enter();
    void update();

private:
    static ReferenceState instance;
};

#endif //METACONTROLSIM_FSSTATE_H
