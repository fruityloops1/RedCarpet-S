#pragma once

#include "al/Camera/CameraDirector.h"
#include "al/Execute/ExecuteDirector.h"
#include "al/Placement/PlacementId.h"
#include <math/seadMatrix.h>

namespace al {

class CameraPoseUpdater;
class SceneCameraCtrl;
class CameraTicketHolder;
class CameraResourceHolder;
class CameraPoser_RS;

class CameraDirector_RS : public IUseExecutor, public IUseCamera {
    u32 mNumPoseUpdaters = 0;
    SceneCameraInfo* mSceneCameraInfo = nullptr;
    SceneCameraCtrl* mSceneCameraCtrl = nullptr;
    CameraPoseUpdater* mPoseUpdaters = nullptr;
    void* _30 = nullptr;
    void* _38 = nullptr;
    CameraTicketHolder* _40 = nullptr;
    void* _48 = nullptr;
    void* _50 = nullptr;
    void* _58 = nullptr;
    void* _60 = nullptr;
    void* _68 = nullptr;
    void* _70 = nullptr;
    void* _78 = nullptr;
    void* _80 = nullptr;
    CameraResourceHolder* _88 = nullptr;
    void* _90 = nullptr;
    void* _98 = nullptr;
    void* _A0 = nullptr;
    void* _A8 = nullptr;
    void* _B0 = nullptr;
    // ...

public:
    void createCamera(CameraPoser_RS* camera, const PlacementId*, const char*, int, const sead::Matrix34f&, bool registerTicket);
};

class IUseCamera_RS {
public:
    virtual CameraDirector_RS* getCameraDirector_RS() const = 0;
};

} // namespace al
