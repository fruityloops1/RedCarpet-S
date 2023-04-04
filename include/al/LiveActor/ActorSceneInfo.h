#pragma once

namespace al {

class AreaObjDirector;
class CameraDirector;
class CameraDirector_RS;
class CollisionDirector;
class SceneObjHolder;

struct ActorSceneInfo {
    SceneObjHolder* mSceneObjHolder = nullptr;
    void* _8 = nullptr;
    CollisionDirector* mCollisionDirector = nullptr;
    void* _18 = nullptr;
    CameraDirector* mCameraDirector = nullptr;
    void* _28 = nullptr;
    void* _30 = nullptr;
    void* _38 = nullptr;
    void* _40 = nullptr;
    AreaObjDirector* mAreaObjDirector = nullptr;
    void* _50 = nullptr;
    void* _58 = nullptr;
    void* _60 = nullptr;
    void* _68 = nullptr;
    void* _70 = nullptr;
    CameraDirector_RS* mCameraDirector_RS = nullptr;
};

} // namespace al
