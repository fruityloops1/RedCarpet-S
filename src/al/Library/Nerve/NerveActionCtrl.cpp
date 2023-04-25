#include "al/Base/String.h"
#include "al/Nerve/NerveActionCtrl.h"

al::NerveAction::NerveAction()
    : mNextNode(nullptr)
{
    alNerveFunction::NerveActionCollector::getCurrentCollector()->addNerve(this);
}

namespace alNerveFunction {

NerveActionCollector* NerveActionCollector::sCurrentCollector;
NerveActionCollector::NerveActionCollector()
{
    sCurrentCollector = this;
}

void NerveActionCollector::addNerve(al::NerveAction* pNerve)
{
    if (mStartNode == nullptr) {
        mStartNode = pNerve;
        mEndNode = pNerve;
    } else {
        mEndNode->mNextNode = pNerve;
        mEndNode = pNerve;
    }
    mNumNodes++;
}

} // namespace alNerveFunction

namespace al {

NerveActionCtrl::NerveActionCtrl(alNerveFunction::NerveActionCollector* pCollector)
{
    mNumNerveActions = pCollector->mNumNodes;
    mNerveActions = new NerveAction*[mNumNerveActions];

    NerveAction* cur = pCollector->mStartNode;
    for (int i = 0; i < mNumNerveActions; i++) {
        mNerveActions[i] = cur;
        cur = cur->mNextNode;
    }
}

NerveAction* NerveActionCtrl::findNerve(const char* pName) const
{
    for (int i = 0; i < mNumNerveActions; i++) {
        NerveAction* cur = mNerveActions[i];
        const char* name = cur->getName();
        if (isEqualString(name, pName))
            return cur;
    }
    return nullptr;
}

} // namespace al
