#pragma once

#include "al/Functor/FunctorBase.h"

namespace al {

class PlacementInfo;
class StageSwitchAccesser;
class StageSwitchDirector;

class StageSwitchKeeper {
    void* _0;
    void* _8;
    void* _10;

public:
    StageSwitchKeeper();

    void init(StageSwitchDirector*, const PlacementInfo& pInfo);
    StageSwitchAccesser* tryGetStageSwitchAccesser(const char* pName) const;
};

class IUseName {
public:
    virtual const char* getName() const = 0;
};

class IUseStageSwitch : public IUseName {
public:
    virtual StageSwitchKeeper* getStageSwitchKeeper() const = 0;
    virtual void initStageSwitchKeeper();
};

bool tryOnStageSwitch(al::IUseStageSwitch* pUser, const char* pName);
bool tryOffStageSwitch(al::IUseStageSwitch* pUser, const char* pName);
void listenStageSwitchOn(al::IUseStageSwitch* pUser, const char* pName, const FunctorBase& pFunctor);
void listenStageSwitchOff(al::IUseStageSwitch* pUser, const char* pName, const FunctorBase& pFunctor);

} // namespace al
