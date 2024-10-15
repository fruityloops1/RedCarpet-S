#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

class NerveStateBase;

void setNerve(IUseNerve* user, const Nerve* nerve);
void setNerveAtStep(IUseNerve* user, const Nerve* nerve, s32 step);
bool isStep(const IUseNerve* user, s32 step);
bool isNerve(const IUseNerve* user, const Nerve* nerve);
s32 getNerveStep(const IUseNerve* user);
const Nerve* getNerve(const IUseNerve* user);
bool isFirstStep(const IUseNerve* user);
bool isLessStep(const IUseNerve* user, s32 compare);
bool isLessEqualStep(const IUseNerve* user, s32 compare);
bool isGreaterStep(const IUseNerve* user, s32 compare);
bool isGreaterEqualStep(const IUseNerve* user, s32 compare);
bool isIntervalStep(const IUseNerve* user, s32 interval, s32 unk = 0);
bool isNewNerve(const IUseNerve* user);
float calcNerveRate(const IUseNerve* user, s32 rate);
float calcNerveRate(const IUseNerve* user, s32 rate, s32);
float calcNerveValue(const IUseNerve* user, s32, s32, float, float);
float calcNerveJumpValue(const IUseNerve* user, s32, s32, s32, float);
void initNerveState(IUseNerve* user, NerveStateBase* state, const Nerve* hostStateNrv, const char* name);
void addNerveState(IUseNerve* user, NerveStateBase* state, const Nerve* hostStateNrv, const char* name);
bool updateNerveState(IUseNerve* user);
bool updateNerveStateAndNextNerve(IUseNerve* user, const Nerve* nextNrv);

} // namespace al
