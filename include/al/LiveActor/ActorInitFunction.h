#pragma once

#include "al/LiveActor/ActorSceneFunction.h"
#include "al/Placement/PlacementId.h"

namespace al {

class PlacementInfo;
class LayoutInitInfo;
class ExecuteDirector;
class AudioDirector;
class EffectSystemInfo;
class OceanWaveDirector;
class HitSensorDirector;
class StageSwitchDirector;
class ScreenPointDirector;
class LiveActorGroup;

class ActorInitInfo {
    const PlacementInfo* mPlacementInfo = nullptr;
    const LayoutInitInfo* mLayoutInitInfo = nullptr;
    ActorSceneInfo mActorSceneInfo;
    ExecuteDirector* mExecuteDirector = nullptr;
    AudioDirector* mAudioDirector = nullptr;
    EffectSystemInfo* mEffectSystemInfo = nullptr;
    OceanWaveDirector* mOceanWaveDirector = nullptr;
    HitSensorDirector* mHitSensorDirector = nullptr;
    StageSwitchDirector* mStageSwitchDirector = nullptr;
    ScreenPointDirector* mScreenPointDirector = nullptr;
    PlacementId* mPlacementId = new PlacementId;
    LiveActorGroup* mLiveActorGroup = nullptr;

public:
    ActorInitInfo();

    const PlacementInfo* getPlacementInfo() const { return mPlacementInfo; }

    void initNew(
        const PlacementInfo* pPlacementInfo,
        const LayoutInitInfo* pLayoutInitInfo,
        ExecuteDirector* pExecuteDirector,
        AudioDirector* pAudioDirector,
        EffectSystemInfo* pEffectSystemInfo,
        OceanWaveDirector* pOceanWaveDirector,
        SceneObjHolder* pSceneObjHolder,
        SceneStopCtrl* pSceneStopCtrl,
        ScreenCoverCtrl* pScreenCoverCtrl,
        HitSensorDirector* pHitSensorDirector,
        ScreenPointDirector* pScreenPointDirector,
        ClippingDirectorBase* pClippingDirectorBase,
        CollisionDirector* pCollisionDirector,
        AreaObjDirector* pAreaObjDirector,
        StageSwitchDirector* pStageSwitchDirector,
        PlayerHolder* pPlayerHolder,
        ItemDirectorBase* pItemDirectorBase,
        ShadowDirector* pShadowDirector,
        PadRumbleDirector* pPadRumbleDirector,
        CameraDirector_RS* pCameraDirector_RS,
        GraphicsSystemInfo* pGraphicsSystemInfo,
        SceneCameraInfo* pSceneCameraInfo,
        DemoDirector* pDemoDirector,
        LiveActorGroup* pLiveActorGroup,
        bool pUnk);
};

class LiveActor;

void initActorPoseTFGSV(LiveActor* pActor);
void initActorPoseTFSV(LiveActor* pActor);
void initActorPoseTQSV(LiveActor* pActor);
void initActorPoseTRMSV(LiveActor* pActor);
void initActorPoseTRSV(LiveActor* pActor);
void initActorSRT(LiveActor* pActor, const ActorInitInfo& pInfo);

} // namespace al
