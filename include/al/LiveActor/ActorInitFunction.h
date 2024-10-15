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
        const PlacementInfo* placementInfo,
        const LayoutInitInfo* layoutInitInfo,
        ExecuteDirector* executeDirector,
        AudioDirector* audioDirector,
        EffectSystemInfo* effectSystemInfo,
        OceanWaveDirector* oceanWaveDirector,
        SceneObjHolder* sceneObjHolder,
        SceneStopCtrl* sceneStopCtrl,
        ScreenCoverCtrl* screenCoverCtrl,
        HitSensorDirector* hitSensorDirector,
        ScreenPointDirector* screenPointDirector,
        ClippingDirectorBase* clippingDirectorBase,
        CollisionDirector* collisionDirector,
        AreaObjDirector* areaObjDirector,
        StageSwitchDirector* stageSwitchDirector,
        PlayerHolder* playerHolder,
        ItemDirectorBase* itemDirectorBase,
        ShadowDirector* shadowDirector,
        PadRumbleDirector* padRumbleDirector,
        CameraDirector_RS* cameraDirector_RS,
        GraphicsSystemInfo* graphicsSystemInfo,
        SceneCameraInfo* sceneCameraInfo,
        DemoDirector* demoDirector,
        LiveActorGroup* liveActorGroup,
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
