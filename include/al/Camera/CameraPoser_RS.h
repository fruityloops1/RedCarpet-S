#pragma once

#include "al/AreaObj/AreaObjDirector.h"
#include "al/Audio/AudioKeeper.h"
#include "al/Collision/CollisionDirector.h"
#include "al/Nerve/NerveKeeper.h"
#include "al/Placement/PlacementInfo.h"
#include "al/Rail/RailKeeper.h"
#include "al/Rail/RailRider.h"
#include "al/Util/IUseName.h"
#include <gfx/seadCamera.h>

namespace al {

class CameraVerticalAbsorber;
class CameraAngleCtrlInfo;
class CameraAngleSwingInfo;
class CameraArrowCollider;
class CameraObjectRequestInfo;
class CameraOffsetCtrlPreset;
class CameraParamMoveLimit;
class GyroCameraCtrl;
class SnapShotCameraCtrl;
class CameraTurnInfo;
class CameraViewInfo;
class CameraStartInfo;
class CameraPoserFlag;

class CameraPoser_RS : public al::IUseAreaObj, public al::IUseAudioKeeper, public al::IUseCollision, public al::IUseName, public al::IUseNerve, public al::IUseRail {
    const char* mName = nullptr;
    float _38;
    sead::Vector3f mPosition;
    sead::Vector3f mTargetTrans = sead::Vector3f::ex;
    sead::Vector3f mCameraUp = sead::Vector3f::ey;
    float mFovyDegree = 35.0f;
    float _64;
    sead::Matrix34f mViewMtx = sead::Matrix34f::ident;
    bool _98 = false;
    CameraViewInfo* mViewInfo = nullptr;
    al::AreaObjDirector* mAreaDirector = nullptr;
    CameraPoserFlag* mPoserFlags = nullptr;
    CameraVerticalAbsorber* mVerticalAbsorber = nullptr;
    CameraAngleCtrlInfo* mAngleCtrlInfo = nullptr;
    CameraAngleSwingInfo* mAngleSwingInfo = nullptr;
    CameraArrowCollider* mArrowCollider = nullptr;
    CameraOffsetCtrlPreset* mOffsetCtrlPreset = nullptr;
    float* mLocalInterpole = nullptr;
    float* mLookAtInterpole = nullptr;
    CameraParamMoveLimit* mParamMoveLimit = nullptr;
    void* _F88 = nullptr;
    GyroCameraCtrl* mGyroCtrl = nullptr;
    SnapShotCameraCtrl* mSnapshotCtrl = nullptr;
    AudioKeeper* mAudioKeeper = nullptr;
    NerveKeeper* mNerveKeeper = nullptr;
    RailKeeper* mRailKeeper = nullptr;
    int* _128 = nullptr;
    int* _130 = nullptr;
    sead::Vector3f* mOrthoProjectionParam = nullptr;

public:
    CameraPoser_RS(const char* pName);

    virtual AreaObjDirector* getAreaObjDirector() const override;
    virtual void init();
    virtual void initByPlacementObj(const al::PlacementInfo&);
    virtual void endInit();
    virtual void start(const CameraStartInfo&);
    virtual void update();
    virtual void end();
    virtual void loadParam(const ByamlIter&);
    virtual void makeLookAtCamera(sead::LookAtCamera*) const;
    virtual void receiveRequestFromObject(const CameraObjectRequestInfo&);
    virtual bool isZooming() const;
    virtual bool isEnableRotateByPad() const;
    virtual void startSnapShotMode();
    virtual void endSnapShotMode();

    virtual const char* getName() const override;
    virtual CollisionDirector* getCollisionDirector() const override;
    virtual NerveKeeper* getNerveKeeper() const override;
    virtual AudioKeeper* getAudioKeeper() const override;
    virtual RailRider* getRailRider() const override;

    virtual void load(const ByamlIter& pTicket);
    virtual void movement();
    virtual void calcCameraPose(sead::LookAtCamera*) const;
    virtual void requestTurnToDirection(const al::CameraTurnInfo*);

    bool isInterpoleByCameraDistance() const;
    bool isInterpoleEaseOut() const;
    bool isEndInterpoleByStep() const;
    bool isFirstCalc() const;

    void initNerve(const al::Nerve*, int);
    void initArrowCollider(al::CameraArrowCollider*);
    void initAudioKeeper(const char*);
    void initRail(const al::PlacementInfo&);
    void initLocalInterpole();
    void initLookAtInterpole(float);
    void initOrthoProjectionParam();
    void tryInitAreaLimitter(const al::PlacementInfo&);

    void makeLookAtCameraPrev(sead::LookAtCamera*) const;
    void makeLookAtCameraPost(sead::LookAtCamera*) const;
    void makeLookAtCameraLast(sead::LookAtCamera*) const;
    void makeLookAtCameraCollide(sead::LookAtCamera*) const;

    void getInterpoleStep();
    void setInterpoleStep(int);
    void resetInterpoleStep();
    void setInterpoleEaseOut();
    void getEndInterpoleStep();

    void appear(const al::CameraStartInfo&);
    void calcCameraPose(sead::LookAtCamera*);
    void receiveRequestFromObjectCore(const al::CameraObjectRequestInfo&);

    void startSnapShotModeCore();
    void endSnapShotModeCore();
};

} // namespace al
