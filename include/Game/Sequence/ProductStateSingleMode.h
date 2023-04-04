#pragma once

#include "al/Nerve/HostStateBase.h"
#include "al/Sequence/SceneCreator.h"
#include "al/Sequence/SequenceInitInfo.h"
#include <basis/seadTypes.h>

class ProductSequence;

class ProductStateSingleMode : public al::HostStateBase<ProductSequence>, public al::IUseSceneCreator {
    struct ProductStageStartParam* mStartParam = nullptr;
    void* _30[2];
    al::SequenceInitInfo* mSequenceInitInfo = nullptr;
    void* _48 = nullptr;
    al::SceneCreator* mSceneCreator = nullptr;

public:
    void init() override;
    void appear() override;
    void kill() override;

    al::SceneCreator* getSceneCreator() const override;
    void setSceneCreator(al::SceneCreator*) override;
};
