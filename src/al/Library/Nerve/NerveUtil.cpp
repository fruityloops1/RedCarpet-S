#include "al/Nerve/NerveStateBase.h"
#include "al/Nerve/NerveStateCtrl.h"
#include "al/Nerve/NerveUtil.h"

namespace al {

void setNerve(IUseNerve* pUser, const Nerve* pNrv)
{
    pUser->getNerveKeeper()->setNerve(pNrv);
}

void setNerveAtStep(IUseNerve* pUser, const Nerve* pNrv, int pStep)
{
    if (pUser->getNerveKeeper()->getStep() == pStep)
        setNerve(pUser, pNrv);
}

bool isStep(const IUseNerve* pUser, int pStep)
{
    return getNerveStep(pUser) == pStep;
}

bool isNerve(const IUseNerve* pUser, const Nerve* pNrv)
{
    return getNerve(pUser) == pNrv;
}

s32 getNerveStep(const IUseNerve* pUser)
{
    return pUser->getNerveKeeper()->getStep();
}

const Nerve* getNerve(const IUseNerve* pUser)
{
    return pUser->getNerveKeeper()->getCurrentNerve();
}

bool isFirstStep(const IUseNerve* pUser)
{
    return getNerveStep(pUser) == 0;
}

bool isLessStep(const IUseNerve* pUser, s32 pCmp)
{
    return getNerveStep(pUser) < pCmp;
}

bool isLessEqualStep(const IUseNerve* pUser, s32 pCmp)
{
    return getNerveStep(pUser) <= pCmp;
}

bool isGreaterStep(const IUseNerve* pUser, s32 pCmp)
{
    return getNerveStep(pUser) > pCmp;
}

bool isGreaterEqualStep(const IUseNerve* pUser, s32 pCmp)
{
    return getNerveStep(pUser) >= pCmp;
}

bool isNewNerve(const IUseNerve* pUser)
{
    return getNerveStep(pUser) >> 0x1f;
}

#ifdef NON_MATCHING
float calcNerveRate(const IUseNerve* pUser, s32 pRate)
{
    if (pRate < 1)
        return 1;
    float progress = float(getNerveStep(pUser)) / pRate;
    if (progress < 0)
        return 0;
    if (progress > 1)
        return 1;
    return progress;
}
#endif

void initNerveState(IUseNerve* pUser, NerveStateBase* pState, const Nerve* pHostStateNrv, const char* pName)
{
    pState->init();
    addNerveState(pUser, pState, pHostStateNrv, pName);
}

void addNerveState(IUseNerve* pUser, NerveStateBase* pState, const Nerve* pHostStateNrv, const char* pName)
{
    pUser->getNerveKeeper()->getNerveStateCtrl()->addState(pState, pHostStateNrv, pName);
}

bool updateNerveState(IUseNerve* pUser)
{
    return pUser->getNerveKeeper()->getNerveStateCtrl()->updateCurrentState();
}

bool updateNerveStateAndNextNerve(IUseNerve* pUser, const Nerve* pNextNrv)
{
    if (updateNerveState(pUser)) {
        setNerve(pUser, pNextNrv);
        return true;
    }
    return false;
}

} // namespace al
