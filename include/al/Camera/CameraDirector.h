#pragma once

#include "al/Audio/AudioKeeper.h"
#include "gfx/seadCamera.h"
#include "math/seadVectorFwd.h"
#include <gfx/seadProjection.h>

namespace al {

class ActorInitInfo;
class AreaObj;
class AreaObjDirector;
class CameraAreaObserver;
class CameraCloseUpper;
class CameraCreator;
class CameraInterpole;
class CameraRailHolder;
class CameraPoser;
class CameraSwitcher;
class CollisionDirector;
class ControlAngleParam;
class GyroCameraController;
class PlayerHolder;
class PlayerWatcher;
class SceneCameraInfo;
class SettingParam;
class UserCameraController;

class CameraDirector : public IUseAudioKeeper {
    void* _8;
    void* _10;
    sead::PerspectiveProjection* _18;
    sead::PerspectiveProjection* _20;
    void* _28;
    CameraPoser* _30;
    void* _38;
    CameraAreaObserver* _40;
    CameraInterpole* _48;
    void* _50;
    CameraSwitcher* _58;
    PlayerWatcher* _60;
    CameraCreator* _68;
    UserCameraController* _70;
    GyroCameraController* _78;
    CameraRailHolder* _80;
    CameraCloseUpper* _88;
    CollisionDirector* _90;
    AreaObjDirector* _98;
    u8 _A0[152];
    SettingParam* _138;
    ControlAngleParam* _140;
    AudioKeeper* _148;
    u8 _150[156];

public:
    CameraDirector(s32, AreaObjDirector*, CollisionDirector*);

    void init(const PlayerHolder*);
    void setCameraFromCameraArea(const AreaObj* pObj);
    void initAudioKeeper(ActorInitInfo& pInfo);

    AudioKeeper* getAudioKeeper() const override;
    void reviseCameraInfo(SceneCameraInfo*);
    void update(bool);
    bool isAppearCameraFrame(const sead::LookAtCamera& pCamera) const;
    bool isPlayerOutsideCameraFrame() const;
    bool isSubCameraGyroMode() const;
    float getSnapshotRollDeg();
    void setGoalPosPtr(const sead::Vector3f*);
    void setStageName(const char* pStageName);
    void setCameraMode(s32);
    s32 getCameraMode();
    void switchCameraMode();
    bool isValidUserCameraControlMode() const;
    bool isValidGyroMode() const;
    bool isUserControlMoveLimited() const;
    bool isDisplayCameraIcon() const;
    bool isInCameraIconDisplayArea() const;
    void invalidUserCameraControlByPort(s32 pPort);
    void validUserCameraControlByPort(s32 pPort);
    void validUserCameraControlByPortOnly(s32 pPort);
    bool isRequestGyroMode() const;
    void resetRequestGyroModeFlag();
    bool isRequestOffGyroMode() const;
    void resetRequestOffGyroMode();
    void setSingleJoyconCameraValid(bool);
    void startSnapshotMode();
    void endSnapshotMode();
};

class SceneCameraInfo;

class IUseCamera {
public:
    virtual SceneCameraInfo* getSceneCameraInfo() const = 0;
};

} // namespace al
