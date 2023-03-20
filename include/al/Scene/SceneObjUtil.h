#pragma once

#include "al/Base/Types.h"

namespace al {

class IUseSceneObjHolder;
class ISceneObj;

ISceneObj* createSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx);
void setSceneObj(const IUseSceneObjHolder* pUser, ISceneObj* pObj, s32 pIdx);
ISceneObj* getSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx);
ISceneObj* tryGetSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx);
bool isExistSceneObj(const IUseSceneObjHolder* pUser, s32 pIdx);

} // namespace al
