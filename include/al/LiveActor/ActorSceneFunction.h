#pragma once

namespace al {

class SceneObjHolder;
class ClippingDirectorBase;
class CollisionDirector;
class PlayerHolder;
class SceneCameraInfo;
class SceneStopCtrl;
class ScreenCoverCtrl;
class ItemDirectorBase;
class DemoDirector;
class AreaObjDirector;
class ShadowDirector;
class PadRumbleDirector;
class CameraDirector_RS;
class GraphicsSystemInfo;

class ActorSceneInfo {
    SceneObjHolder* mSceneObjHolder = nullptr;
    ClippingDirectorBase* mClippingDirectorBase = nullptr;
    CollisionDirector* mCollisionDirector = nullptr;
    PlayerHolder* mPlayerHolder = nullptr;
    SceneCameraInfo* mSceneCameraInfo = nullptr;
    SceneStopCtrl* mSceneStopCtrl = nullptr;
    ScreenCoverCtrl* mScreenCoverCtrl = nullptr;
    ItemDirectorBase* mItemDirectorBase = nullptr;
    DemoDirector* mDemoDirector = nullptr;
    AreaObjDirector* mAreaObjDirector = nullptr;
    ShadowDirector* mShadowDirector = nullptr;
    PadRumbleDirector* mPadRumbleDirector = nullptr;
    CameraDirector_RS* mCameraDirector_RS = nullptr;
    bool _68 = false;
    void* _70 = nullptr;
    GraphicsSystemInfo* mGraphicsSystemInfo = nullptr;

public:
    ActorSceneInfo();
};

} // namespace al
