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
    FSState(std::shared_ptr<Machine> fscs);

protected:
    //void changeState(std::unique_ptr<FSState> newstate);
    bool isRunSwitchOn() const;
    bool isMixHigh() const;
    //bool isSampletime() const;
    //bool isReferencetime() const;
    int timeinstate = 0;
    //float getEC() const;
    std::shared_ptr<FSCS> fscs;
};

class OffState : public FSState {
public:
    OffState(std::shared_ptr<Machine> fscs) : FSState(fscs) { enter(); }
    void enter() {}
    void update();

private:
};

class FastFillState : public FSState {
public:
    FastFillState(std::shared_ptr<Machine> fscs) : FSState(fscs) { enter(); }
    void enter();
    void update();
};

class StandbyState : public FSState {
public:
    StandbyState(std::shared_ptr<Machine> fscs) : FSState(fscs) { enter(); }
    void enter() { }
    void update() { }
    void sampleTimer();
    void referenceTimer();
    void turnOff();
};

class BatchState : public FSState {
public:
    BatchState(std::shared_ptr<Machine> fscs) : FSState(fscs) { enter(); }
    void enter();
    void update();
};

class SampleState : public FSState {
public:
    SampleState(std::shared_ptr<Machine> fscs) : FSState(fscs) { enter(); }
    void enter();
    void update();
};

class RefreshState : public FSState {
public:
    RefreshState(std::shared_ptr<Machine> fscs) : FSState(fscs) { enter(); }
    void enter();
    void update();
};

class ReferenceState : public FSState {
public:
    ReferenceState(std::shared_ptr<Machine> fscs) : FSState(fscs) { enter(); }
    void enter() { }
    void update() { }
};

#endif //METACONTROLSIM_FSSTATE_H