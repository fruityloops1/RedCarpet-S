#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

class NerveExecutor : public IUseNerve {
    al::NerveKeeper* mNerveKeeper = nullptr;

public:
    NerveExecutor(const char* pName);

    virtual NerveKeeper* getNerveKeeper() const;
    virtual ~NerveExecutor();

    void initNerve(const Nerve* pStartNerve, int pMaxNerveStates = 0);
    void updateNerve();
};

} // namespace al
