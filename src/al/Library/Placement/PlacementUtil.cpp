#include "al/Base/String.h"
#include "al/LiveActor/ActorInitFunction.h"
#include "al/Placement/PlacementInfo.h"
#include "al/Placement/PlacementUtil.h"
#include "al/Yaml/ByamlUtil.h"

namespace al {

bool isPlaced(const ActorInitInfo& pInfo)
{
    return pInfo.getPlacementInfo()->getPlacementIter().isValid();
}

void getObjectName(const char** pOut, const ActorInitInfo& pInfo)
{
    tryGetObjectName(pOut, pInfo);
}

bool tryGetObjectName(const char** pOut, const ActorInitInfo& pInfo)
{
    return tryGetStringArg(pOut, pInfo, "UnitConfigName");
}

bool tryGetStringArg(const char** pOut, const ActorInitInfo& pInfo, const char* pKey)
{
    const PlacementInfo* info = pInfo.getPlacementInfo();
    const char* name = "";
    if (!info->getPlacementIter().tryGetStringByKey(&name, pKey))
        return false;
    if (isEqualString("", name))
        return false;
    *pOut = name;
    return true;
}

bool isObjectName(const ActorInitInfo& pInfo, const char* pName)
{
    const char* name;
    if (tryGetObjectName(&name, pInfo))
        return isEqualString(name, pName);
    return false;
}

bool isObjectNameSubStr(const ActorInitInfo& pInfo, const char* pSubStr)
{
    const char* name;
    if (tryGetObjectName(&name, pInfo))
        return isEqualSubString(name, pSubStr);
    return false;
}

static bool tryGetStringUnitConfig(const char** pOut, const PlacementInfo& pInfo, const char* pKey)
{
    PlacementInfo unitConfig;
    if (!tryGetPlacementInfoByKey(&unitConfig, pInfo, "UnitConfig"))
        return false;
    const char* className = "";
    if (unitConfig.getPlacementIter().tryGetStringByKey(&className, pKey)) {
        if (isEqualString("", className))
            return false;
        *pOut = className;
        return true;
    }
    return false;
}

bool tryGetClassName(const char** pOut, const PlacementInfo& pInfo)
{
    return tryGetStringUnitConfig(pOut, pInfo, "ParameterConfigName");
}

bool tryGetPlacementInfoByKey(PlacementInfo* pOut, const PlacementInfo& pInfo, const char* pKey)
{
    ByamlIter iter;
    if (!pInfo.getPlacementIter().tryGetIterByKey(&iter, pKey))
        return false;
    pOut->set(iter, pInfo.getUnitConfigIter(), pInfo.get_20(), pInfo.get_28());
    return true;
}

void getClassName(const char** pOut, const ActorInitInfo& pInfo)
{
    tryGetClassName(pOut, *pInfo.getPlacementInfo());
}

bool isClassName(const ActorInitInfo& pInfo, const char* pClassName)
{
    return isClassName(*pInfo.getPlacementInfo(), pClassName);
}

bool isClassName(const PlacementInfo& pInfo, const char* pClassName)
{
    const char* className = nullptr;
    if (tryGetClassName(&className, pInfo))
        return isEqualString(className, pClassName);
    return false;
}

void getDisplayName(const char** pOut, const ActorInitInfo& pInfo)
{
    tryGetDisplayName(pOut, *pInfo.getPlacementInfo());
}

void getDisplayName(const char** pOut, const PlacementInfo& pInfo)
{
    tryGetDisplayName(pOut, pInfo);
}

bool tryGetDisplayName(const char** pOut, const PlacementInfo& pInfo)
{
    return tryGetStringUnitConfig(pOut, pInfo, "DisplayName");
}

bool tryGetTrans(sead::Vector3f* pOut, const ActorInitInfo& pInfo)
{
    return tryGetTrans(pOut, *pInfo.getPlacementInfo());
}

bool tryGetTrans(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    if (al::tryGetByamlV3f(pOut, pInfo.getPlacementIter(), "Translate")) {
        sead::Matrix34f mtx;
        if (tryGetZoneMatrixTR(&mtx, pInfo))
            *pOut *= mtx;
        return true;
    }
    return false;
}

void getTrans(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    tryGetTrans(pOut, pInfo);
}

} // namespace al
