#include "al/Scene/ISceneObj.h"
#include "al/Scene/SceneObjHolder.h"

namespace al {

SceneObjHolder::SceneObjHolder(CreateSceneObjCallback pCallback, int pMaxSceneObjs)
    : mCallback(pCallback)
    , mMaxSceneObjs(pMaxSceneObjs)
{
    mSceneObjs = new ISceneObj*[pMaxSceneObjs];

    for (s32 i = 0; i < mMaxSceneObjs; i++)
        mSceneObjs[i] = nullptr;
}

ISceneObj* SceneObjHolder::create(s32 pIdx)
{
    if (mSceneObjs[pIdx])
        return mSceneObjs[pIdx];

    mSceneObjs[pIdx] = mCallback(pIdx);
    mSceneObjs[pIdx]->initSceneObj();
    return mSceneObjs[pIdx];
}

ISceneObj* SceneObjHolder::tryGetObj(s32 pIdx) const { return mSceneObjs[pIdx]; }
ISceneObj* SceneObjHolder::getObj(s32 pIdx) const { return tryGetObj(pIdx); }
bool SceneObjHolder::isExist(s32 pIdx) const { return mSceneObjs[pIdx] != nullptr; }
void SceneObjHolder::setSceneObj(ISceneObj* pObj, s32 pIdx) { mSceneObjs[pIdx] = pObj; }

void SceneObjHolder::initAfterPlacementSceneObj(const ActorInitInfo& info)
{
    for (s32 i = 0; i < mMaxSceneObjs; i++)
        if (mSceneObjs[i])
            mSceneObjs[i]->initAfterPlacementSceneObj(info);
}

} // namespace al
