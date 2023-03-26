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

s32 tryGetLayerID(const ByamlIter& pInfo);

} // namespace al

namespace alPlacementFunction {

void getClippingViewId(al::PlacementId* pOut, const al::PlacementInfo& pInfo);

} // namespace alPlacementFunction
