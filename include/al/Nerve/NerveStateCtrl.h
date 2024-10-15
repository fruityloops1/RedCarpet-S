#pragma once

#include "al/Nerve/Nerve.h"
#include <container/seadPtrArray.h>

namespace al {

class NerveStateBase;
class NerveStateCtrl {
public:
    struct State {
        NerveStateBase* mState;
        const Nerve* mHostStateNrv;
        const char* mName;
    };

private:
    s32 mCapacity = 0;
    s32 mNumStates = 0;
    State* mStates = nullptr;
    State* mCurrentState = nullptr;

public:
    NerveStateCtrl(int pMaxNerveStates);

    void addState(NerveStateBase* state, const Nerve* nerve, const char* name);
    bool updateCurrentState();
    void startState(const Nerve* nerve);
    State* findStateInfo(const Nerve* nerve);
    bool isCurrentStateEnd() const;
    void tryEndCurrentState();
};

} // namespace al