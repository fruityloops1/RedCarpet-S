#include "al/Nerve/NerveStateBase.h"
#include "al/Nerve/NerveStateCtrl.h"

namespace al {

NerveStateCtrl::NerveStateCtrl(int pMaxNerveStates)
    : mCapacity(pMaxNerveStates)
{
    mStates = new State[pMaxNerveStates];
    for (int i = 0; i < mCapacity; i++) {
        State* state = &mStates[i];
        state->mState = nullptr;
        state->mHostStateNrv = nullptr;
        state->mName = nullptr;
    }
}

void NerveStateCtrl::addState(NerveStateBase* pState, const Nerve* pNrv, const char* pName)
{
    State* state = &mStates[mNumStates];
    state->mState = pState;
    state->mHostStateNrv = pNrv;
    state->mName = pName;
    mNumStates++;
}

bool NerveStateCtrl::updateCurrentState()
{
    if (mCurrentState)
        return mCurrentState->mState->update();
    return false;
}

void NerveStateCtrl::startState(const Nerve* pNrv)
{
    mCurrentState = findStateInfo(pNrv);

    if (mCurrentState)
        mCurrentState->mState->appear();
}

bool NerveStateCtrl::isCurrentStateEnd() const
{
    if (mCurrentState)
        return mCurrentState->mState->isDead();
    return false;
}

void NerveStateCtrl::tryEndCurrentState()
{
    if (mCurrentState && !isCurrentStateEnd()) {
        mCurrentState->mState->kill();
        mCurrentState = nullptr;
    }
}

NerveStateCtrl::State* NerveStateCtrl::findStateInfo(const Nerve* pNrv)
{
    for (int i = 0; i < mNumStates; i++) {
        State* state = &mStates[i];

        if (state->mHostStateNrv == pNrv)
            return state;
    }

    return nullptr;
}

} // namespace al
