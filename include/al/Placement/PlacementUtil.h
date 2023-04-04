#pragma once

#include "al/Base/Types.h"
#include "al/Yaml/ByamlIter.h"
#include <math/seadMatrix.h>
#include <math/seadVectorFwd.h>

namespace al {

class ActorInitInfo;
class PlacementId;
class PlacementInfo;

bool isPlaced(const ActorInitInfo& pInfo);
void getObjectName(const char** pOut, const ActorInitInfo& pInfo);
bool tryGetObjectName(const char** pOut, const ActorInitInfo& pInfo);
bool tryGetStringArg(const char** pOut, const ActorInitInfo& pInfo, const char* pKey);
bool isObjectName(const ActorInitInfo& pInfo, const char* pName);
bool isObjectNameSubStr(const ActorInitInfo& pInfo, const char* pSubStr);
bool tryGetClassName(const char** pOut, const PlacementInfo& pInfo);
bool tryGetPlacementInfoByKey(PlacementInfo* pOut, const PlacementInfo& pInfo, const char* pKey);
void getClassName(const char** pOut, const ActorInitInfo& pInfo);
bool isClassName(const ActorInitInfo& pInfo, const char* pClassName);
bool isClassName(const PlacementInfo& pInfo, const char* pClassName);
void getDisplayName(const char** pOut, const ActorInitInfo& pInfo);
void getDisplayName(const char** pOut, const PlacementInfo& pInfo);
bool tryGetDisplayName(const char** pOut, const PlacementInfo& pInfo);
bool tryGetTrans(sead::Vector3f* pOut, const ActorInitInfo& pInfo);
bool tryGetTrans(sead::Vector3f* pOut, const PlacementInfo& pInfo);
void getTrans(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetZoneMatrixTR(sead::Matrix34f* pOut, const PlacementInfo& pInfo);
bool tryGetRotate(sead::Vector3f* pOut, const ActorInitInfo& pInfo);
bool tryGetRotate(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetRotate_ParentY(sead::Vector3f* pOut, const ActorInitInfo& pInfo);
bool tryGetRotate_ParentY(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetZoneR(sead::Vector3f* pOut, const PlacementInfo& pInfo);
void getRotate(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetQuat(sead::Quatf* pOut, const ActorInitInfo& pInfo);
bool tryGetQuat(sead::Quatf* pOut, const PlacementInfo& pInfo);
void getQuat(sead::Quatf* pOut, const PlacementInfo& pInfo);
bool tryGetScale(sead::Vector3f* pOut, const ActorInitInfo& pInfo);
bool tryGetScale(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetSide(sead::Vector3f* pOut, const ActorInitInfo& pInfo);
bool tryGetSide(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetUp(sead::Vector3f* pOut, const ActorInitInfo& pInfo);
bool tryGetUp(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetFront(sead::Vector3f* pOut, const ActorInitInfo& pInfo);
bool tryGetFront(sead::Vector3f* pOut, const PlacementInfo& pInfo);
bool tryGetLocalAxis(sead::Vector3f* pOut, const ActorInitInfo& pInfo, int pAxis);
bool tryGetLocalAxis(sead::Vector3f* pOut, const PlacementInfo& pInfo, int pAxis);

bool tryGetArg(float* pOut, const al::ActorInitInfo& pInfo, const char* pKey);
bool tryGetArg(bool* pOut, const al::ActorInitInfo& pInfo, const char* pKey);

int calcLinkChildNum(const al::ActorInitInfo& pInfo, const char* pLinkName);
void getLinksInfo(PlacementInfo* pOut, const PlacementInfo& pParentInfo, const char* pLinkName);

s32 tryGetLayerID(const ByamlIter& pInfo);

} // namespace al

namespace alPlacementFunction {

void getClippingViewId(al::PlacementId* pOut, const al::PlacementInfo& pInfo);

} // namespace alPlacementFunction
