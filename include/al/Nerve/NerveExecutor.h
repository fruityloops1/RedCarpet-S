#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

class NerveExecutor : public IUseNerve {
    al::NerveKeeper* mNerveKeeper = nullptr;

public:
    NerveExecutor(const char* name);

    virtual NerveKeeper* getNerveKeeper() const;
    virtual ~NerveExecutor();

    void initNerve(const Nerve* startNerve, int maxNerveStates = 0);
    void updateNerve();
};

} // namespace al
