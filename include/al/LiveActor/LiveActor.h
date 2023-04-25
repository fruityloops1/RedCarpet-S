#pragma once

#include "al/AreaObj/AreaObjDirector.h"
#include "al/Audio/AudioKeeper.h"
#include "al/Camera/CameraDirector.h"
#include "al/Camera/CameraDirector_RS.h"
#include "al/Collision/CollisionDirector.h"
#include "al/Effect/EffectKeeper.h"
#include "al/Nerve/NerveKeeper.h"
#include "al/Scene/SceneObjHolder.h"
#include "al/StageSwitch/StageSwitchKeeper.h"

namespace al {

class ActorPoseKeeperBase;
class ActorExecuteInfo;
class ActorActionKeeper;
class ActorItemKeeper;
class ActorScoreKeeper;
class Collider;
class HitSensorKeeper;
class ScreenPointKeeper;
class HitReactionKeeper;
class RailKeeper;
class ShadowKeeper;
class ActorPrePassLightKeeper;
class SubActorKeeper;
class ActorSceneInfo;
class LiveActorFlag;
class PlacementHolder;
class HitSensor;
class SensorMsg;
class ScreenPointer;
class ScreenPointTarget;
class SklAnimRetargettingInfo;
class ActorParamHolder;

struct Unknown {
    void* unknown = nullptr;
};

class LiveActor : public IUseNerve,
                  public IUseEffectKeeper,
                  public IUseAudioKeeper,
                  Unknown,
                  public IUseStageSwitch,
                  public IUseSceneObjHolder,
                  public IUseAreaObj,
                  public IUseCamera_RS,
                  public IUseCamera,
                  public IUseCollision {
protected:
    const char* const mName = nullptr;
    ActorPoseKeeperBase* mActorPoseKeeper = nullptr;
    ActorExecuteInfo* mActorExecuteInfo = nullptr;
    ActorActionKeeper* mActionKeeper = nullptr;
    ActorItemKeeper* mActorItemKeeper = nullptr;
    ActorScoreKeeper* mActorScoreKeeper = nullptr;
    Collider* mCollider = nullptr;
    CollisionParts* mCollisionParts = nullptr;
    ModelKeeper* mModelKeeper = nullptr;
    NerveKeeper* mNerveKeeper = nullptr;
    HitSensorKeeper* mHitSensorKeeper = nullptr;
    ScreenPointKeeper* mScreenPointKeeper = nullptr;
    EffectKeeper* mEffectKeeper = nullptr;
    AudioKeeper* mAudioKeeper = nullptr;
    HitReactionKeeper* mHitReactionKeeper = nullptr;
    StageSwitchKeeper* mStageSwitchKeeper = nullptr;
    RailKeeper* mRailKeeper = nullptr;
    ShadowKeeper* mShadowKeeper = nullptr;
    ActorPrePassLightKeeper* mActorPrePassLightKeeper = nullptr;
    SubActorKeeper* mSubActorKeeper = nullptr;
    ActorParamHolder* mParamHolder = nullptr;
    ActorSceneInfo* mActorSceneInfo = nullptr;
    void* _100 = nullptr;
    LiveActorFlag* mLiveActorFlag = nullptr;
    void* _110 = nullptr;
    PlacementHolder* mPlacementHolder = nullptr;
    void* _120 = nullptr;
    void* _128 = nullptr;
    void* _130 = nullptr;
    LiveActor* mFarLodActor = nullptr;
    void* _140;

public:
    LiveActor(const char* name);

    NerveKeeper* getNerveKeeper() const override;
    virtual ~LiveActor();
    virtual void init(const ActorInitInfo& info);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void reappear();
    virtual void respawn();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void killComplete(bool);
    virtual void makeActorDead();
    virtual void showActor();
    virtual void hideActor();
    virtual void startDemoActor(int);
    virtual void endDemoActor(int);
    virtual void changeScenarioID(int, bool);
    virtual void updateLinkedTrans(const sead::Vector3f& trans);
    virtual void movement();
    virtual void movementPaused(bool);
    virtual void calcAnim();
    virtual void modelUpdate();
    virtual void pausedModelUpdate();
    virtual void draw() const;
    virtual void pause();
    virtual void resume();
    virtual void startClipped();
    virtual void endClipped();
    virtual void startClippedByLod();
    virtual void endClippedByLod();
    virtual void startFarLod();
    virtual void endFarLod();
    virtual bool isFarLodSwitchOkay();
    virtual bool canLinkYOffset() const;
    virtual void attackSensor(HitSensor* pMe, HitSensor* pOther);
    virtual bool receiveMsg(const SensorMsg* pMsg, HitSensor* pOther, HitSensor* pMe);
    virtual bool receiveMsgScreenPoint(const SensorMsg* pMsg, ScreenPointer* pPointer, ScreenPointTarget* pTarget);
    virtual bool receiveMsgScreenPointSM(const SensorMsg* pMsg, ScreenPointer* pPointer, ScreenPointTarget* pTarget);
    const char* getName() const override;
    virtual const sead::Matrix34f& getBaseMtx();
    EffectKeeper* getEffectKeeper() const override;
    AudioKeeper* getAudioKeeper() const override;
    StageSwitchKeeper* getStageSwitchKeeper() const override;
    SceneObjHolder* getSceneObjHolder() const override;
    CollisionDirector* getCollisionDirector() const override;
    AreaObjDirector* getAreaObjDirector() const override;
    SceneCameraInfo* getSceneCameraInfo() const override;
    CameraDirector_RS* getCameraDirector_RS() const override;
    virtual bool isInRouteDokan() const;
    void initStageSwitchKeeper() override;
    virtual LiveActor* getLinkedActor();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void updateCollider();

    void initActionKeeper(const char*, const char*);
    void initActorPrePassLightKeeper(ActorPrePassLightKeeper*);
    void initCollider(float pRadius, float pYOffset, u32);
    void initExecuteInfo(ActorExecuteInfo*);
    void initHitSensor(int pSensorAmount);
    void initItemKeeper(int);
    void initModelKeeper(ModelKeeper*);
    void initNerveKeeper(NerveKeeper*);
    void initPoseKeeper(ActorPoseKeeperBase*);
    void initRailKeeper(const ActorInitInfo& pInfo);
    void initSceneInfo(ActorSceneInfo*);
    void initScoreKeeper();
    void initScreenPointKeeper(int pTargetAmount);
    void initShadowKeeper(ShadowKeeper*);

    ActorPoseKeeperBase* getActorPoseKeeper() const { return mActorPoseKeeper; }
    SubActorKeeper* getSubActorKeeper() const { return mSubActorKeeper; }
    PlacementHolder* getPlacementHolder() const { return mPlacementHolder; }
    LiveActorFlag* getLiveActorFlag() const { return mLiveActorFlag; }
};

} // namespace al
