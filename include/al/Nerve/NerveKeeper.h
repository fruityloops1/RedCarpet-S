#pragma once

#include "al/Base/Types.h"

namespace al {

class Nerve;
class NerveStateCtrl;
class NerveActionCtrl;

class NerveKeeper;
class IUseNerve {
public:
    virtual NerveKeeper* getNerveKeeper() const = 0;
};

class NerveActionCtrl;
class NerveKeeper {
    IUseNerve* mUser = nullptr;
    const Nerve* mLastNerve = nullptr;
    const Nerve* mNerve = nullptr;
    s32 mStep = 0;
    s32 _1C;
    NerveStateCtrl* mNerveStateCtrl = nullptr;
    NerveActionCtrl* mNerveActionCtrl = nullptr;

public:
    NerveKeeper(void* nerveUser, const Nerve* startNerve, int maxNerveStates = 0);

    void update();
    void setNerve(const Nerve* nerve);
    const Nerve* getCurrentNerve() const;
    void initNerveAction(NerveActionCtrl*);

    IUseNerve* getUser() const { return mUser; }
    s32 getStep() const { return mStep; }
    NerveStateCtrl* getNerveStateCtrl() const { return mNerveStateCtrl; }
    NerveActionCtrl* getNerveActionCtrl() const { return mNerveActionCtrl; }
};

} // namespace al