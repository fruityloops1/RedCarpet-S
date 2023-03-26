#include "al/Scene/SceneObjHolder.h"
#include "al/Scene/SceneObjUtil.h"

namespace al {

ISceneObj* createSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx) { return pUser->getSceneObjHolder()->create(pIdx); }
void setSceneObj(const IUseSceneObjHolder* pUser, ISceneObj* pObj, s32 pIdx) { pUser->getSceneObjHolder()->setSceneObj(pObj, pIdx); }
ISceneObj* getSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx) { return pUser->getSceneObjHolder()->getObj(pIdx); }
ISceneObj* tryGetSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx) { return pUser->getSceneObjHolder()->tryGetObj(pIdx); }
bool isExistSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx) { return pUser->getSceneObjHolder()->isExist(pIdx); }

} // namespace al
