#include "al/Nerve/NerveExecutor.h"

namespace al {

NerveExecutor::NerveExecutor(const char* pName) { }
NerveExecutor::~NerveExecutor()
{
    if (mNerveKeeper)
        delete mNerveKeeper;
}

void NerveExecutor::initNerve(const Nerve* pStartNerve, int pMaxNerveStates)
{
    mNerveKeeper = new NerveKeeper(this, pStartNerve, pMaxNerveStates);
}

void NerveExecutor::updateNerve()
{
    if (mNerveKeeper)
        mNerveKeeper->update();
}

} // namespace al
