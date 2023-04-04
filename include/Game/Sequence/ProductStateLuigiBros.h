#pragma once

#include "Game/Scene/LuigiBrosScene.h"
#include "Game/Sequence/StageWipeKeeper.h"
#include "al/Nerve/HostStateBase.h"
#include "al/Screen/ScreenCaptureExecutor.h"
#include "al/Sequence/SceneCreator.h"
#include "al/Sequence/SequenceInitInfo.h"

class GameDataHolder;
class ProductSequence;

class ProductStateLuigiBros : public al::HostStateBase<ProductSequence>, public al::IUseSceneCreator {
    al::SceneCreator* mSceneCreator = nullptr;
    StageWipeKeeper* mWipeKeeper = nullptr;
    LuigiBrosScene* mScene = nullptr;
    void* _40 = nullptr;
    void* _48 = nullptr;

public:
    ProductStateLuigiBros(ProductSequence* pHost, void* unk1, const al::SequenceInitInfo& pInfo, void* unk2, GameDataHolder* pGameDataHolder, StageWipeKeeper* pStageWipeKeeper, al::ScreenCaptureExecutor* pScreenCaptureExecutor);

    void init() override;
    void appear() override;
    al::SceneCreator* getSceneCreator() const override { return mSceneCreator; }
    void setSceneCreator(al::SceneCreator* p) override { mSceneCreator = p; }

    void exeLoad();
    void exeWait();
};
