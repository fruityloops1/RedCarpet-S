#pragma once

#include "al/Base/Types.h"

namespace al {

class ActorInitInfo;
class ISceneObj;

class SceneObjHolder {
public:
    using CreateSceneObjCallback = ISceneObj* (*)(int);

private:
    CreateSceneObjCallback mCallback = nullptr;
    ISceneObj** mSceneObjs;
    s32 mMaxSceneObjs = 0;

public:
    SceneObjHolder(CreateSceneObjCallback pCallback, int pMaxSceneObjs);

    ISceneObj* create(s32 pIdx);
    ISceneObj* tryGetObj(s32 pIdx) const;
    ISceneObj* getObj(s32 pIdx) const;
    bool isExist(s32 pIdx) const;
    void setSceneObj(ISceneObj* pObj, s32 pIdx);
    void initAfterPlacementSceneObj(const ActorInitInfo& info);
};

class IUseSceneObjHolder {
public:
    virtual SceneObjHolder* getSceneObjHolder() const = 0;
};

} // namespace al
