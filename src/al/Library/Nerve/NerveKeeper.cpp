#include "al/Nerve/NerveKeeper.h"
#include "al/Nerve/NerveStateCtrl.h"

namespace al {

NerveKeeper::NerveKeeper(void* pNerveUser, const Nerve* pStartNerve, int pMaxNerveStates)
    : mUser(reinterpret_cast<IUseNerve*>(pNerveUser))
    , mNerve(pStartNerve)
    , mStep(0)
{
    if (pMaxNerveStates > 0)
        mNerveStateCtrl = new NerveStateCtrl(pMaxNerveStates);
}

void NerveKeeper::update()
{ // ):
    const Nerve* updateNerve = mNerve;

    if (updateNerve) {
        if (mNerveStateCtrl) {
            mNerveStateCtrl->tryEndCurrentState();
            mNerveStateCtrl->startState(mNerve);
            updateNerve = mNerve;
        }

        mLastNerve = updateNerve;
        mNerve = nullptr;
        mStep = 0;
    } else
        updateNerve = mLastNerve;

    updateNerve->execute(this);
    mStep++;

    if (mNerve) {
        if (mNerveStateCtrl) {
            mNerveStateCtrl->tryEndCurrentState();
            mNerveStateCtrl->startState(mNerve);
            updateNerve = mNerve;
        }

        mLastNerve = mNerve;
        mNerve = nullptr;
        mStep = 0;
    }
}

void NerveKeeper::setNerve(const Nerve* pNrv)
{
    if (mStep > -1 && mLastNerve)
        mLastNerve->executeOnEnd(this);
    mNerve = pNrv;
    mStep = -1;
}

const Nerve* NerveKeeper::getCurrentNerve() const
{
    return mNerve ? mNerve : mLastNerve;
}

void NerveKeeper::initNerveAction(NerveActionCtrl* pNerveActionCtrl)
{
    mNerveActionCtrl = pNerveActionCtrl;
}

} // namespace al
