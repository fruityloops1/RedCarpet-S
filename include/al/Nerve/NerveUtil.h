#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

class NerveStateBase;

void setNerve(IUseNerve* pUser, const Nerve* pNrv);
void setNerveAtStep(IUseNerve* pUser, const Nerve* pNrv, s32 pStep);
bool isStep(const IUseNerve* pUser, s32 pStep);
bool isNerve(const IUseNerve* pUser, const Nerve* pNrv);
s32 getNerveStep(const IUseNerve* pUser);
const Nerve* getNerve(const IUseNerve* pUser);
bool isFirstStep(const IUseNerve* pUser);
bool isLessStep(const IUseNerve* pUser, s32 pCmp);
bool isLessEqualStep(const IUseNerve* pUser, s32 pCmp);
bool isGreaterStep(const IUseNerve* pUser, s32 pCmp);
bool isGreaterEqualStep(const IUseNerve* pUser, s32 pCmp);
bool isIntervalStep(const IUseNerve* pUser, s32 pInterval, s32 pUnk = 0);
bool isNewNerve(const IUseNerve* pUser);
float calcNerveRate(const IUseNerve* pUser, s32 pRate);
float calcNerveRate(const IUseNerve* pUser, s32 pRate, s32);
float calcNerveValue(const IUseNerve* pUser, s32, s32, float, float);
float calcNerveJumpValue(const IUseNerve* pUser, s32, s32, s32, float);
void initNerveState(IUseNerve* pUser, NerveStateBase* pState, const Nerve* pHostStateNrv, const char* pName);
void addNerveState(IUseNerve* pUser, NerveStateBase* pState, const Nerve* pHostStateNrv, const char* pName);
bool updateNerveState(IUseNerve* pUser);
bool updateNerveStateAndNextNerve(IUseNerve* pUser, const Nerve* pNextNrv);

} // namespace al
