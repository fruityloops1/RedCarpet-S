#include "al/Base/String.h"
#include "al/LiveActor/ActorInitFunction.h"
#include "al/Math/MathVectorUtil.h"
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
    pOut->set(iter, pInfo.getZoneIter(), pInfo.get_20(), pInfo.get_28());
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

bool tryGetRotate(sead::Vector3f* pOut, const ActorInitInfo& pInfo)
{
    return tryGetRotate(pOut, *pInfo.getPlacementInfo());
}

static void tryAddParentY(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    ByamlIter iter(pInfo.getZoneIter());
    if (iter.isValid()) {
        sead::Vector3f rot(sead::Vector3f::zero);
        if (tryGetByamlV3f(&rot, iter, "Rotate"))
            pOut->y += rot.y;
    }
}

bool tryGetRotate_ParentY(sead::Vector3f* pOut, const ActorInitInfo& pInfo)
{
    return tryGetRotate_ParentY(pOut, *pInfo.getPlacementInfo());
}

bool tryGetRotate_ParentY(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    if (tryGetByamlV3f(pOut, pInfo.getPlacementIter(), "Rotate")) {
        sead::Matrix34f mtx; // unused lol
        if (tryGetZoneMatrixTR(&mtx, pInfo))
            tryAddParentY(pOut, pInfo);

        return true;
    }
    return false;
}

bool tryGetZoneR(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    ByamlIter iter(pInfo.getZoneIter());
    if (!iter.isValid())
        return false;

    sead::Vector3f rot(sead::Vector3f::zero);
    if (tryGetByamlV3f(&rot, iter, "Rotate")) {
        *pOut = rot;
        return true;
    }

    return false;
}

void getRotate(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    tryGetRotate(pOut, pInfo);
}

#ifdef NON_MATCHING // sead quats are incorrect
bool tryGetQuat(sead::Quatf* pOut, const ActorInitInfo& pInfo)
{
    return tryGetQuat(pOut, *pInfo.getPlacementInfo());
}

bool tryGetQuat(sead::Quatf* pOut, const PlacementInfo& pInfo)
{
    sead::Vector3f rot(sead::Vector3f::zero);
    if (!tryGetRotate(&rot, pInfo)) {
        *pOut = sead::Quatf::unit;
        return false;
    }
    pOut->setRPY(sead::Mathf::deg2rad(rot.x), sead::Mathf::deg2rad(rot.y), sead::Mathf::deg2rad(rot.z));
    return true;
}

void getQuat(sead::Quatf* pOut, const PlacementInfo& pInfo)
{
    tryGetQuat(pOut, pInfo);
}
#endif

bool tryGetScale(sead::Vector3f* pOut, const ActorInitInfo& pInfo)
{
    return tryGetScale(pOut, *pInfo.getPlacementInfo());
}

bool tryGetScale(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    return tryGetByamlV3f(pOut, pInfo.getPlacementIter(), "Scale");
}

bool tryGetSide(sead::Vector3f* pOut, const ActorInitInfo& pInfo)
{
    return tryGetSide(pOut, *pInfo.getPlacementInfo());
}

#ifdef NON_MATCHING // tryGetQuat's fault
bool tryGetSide(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    sead::Quatf quat(sead::Quatf::unit);
    if (tryGetQuat(&quat, pInfo)) {
        calcQuatSide(pOut, quat);
        return true;
    }
    return false;
}
#endif

bool tryGetUp(sead::Vector3f* pOut, const ActorInitInfo& pInfo)
{
    return tryGetUp(pOut, *pInfo.getPlacementInfo());
}

#ifdef NON_MATCHING // tryGetQuat's fault
bool tryGetUp(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    sead::Quatf quat(sead::Quatf::unit);
    if (tryGetQuat(&quat, pInfo)) {
        calcQuatUp(pOut, quat);
        return true;
    }
    return false;
}
#endif

bool tryGetFront(sead::Vector3f* pOut, const ActorInitInfo& pInfo)
{
    return tryGetFront(pOut, *pInfo.getPlacementInfo());
}

#ifdef NON_MATCHING // tryGetQuat's fault
bool tryGetFront(sead::Vector3f* pOut, const PlacementInfo& pInfo)
{
    sead::Quatf quat(sead::Quatf::unit);
    if (tryGetQuat(&quat, pInfo)) {
        calcQuatFront(pOut, quat);
        return true;
    }
    return false;
}
#endif

bool tryGetLocalAxis(sead::Vector3f* pOut, const ActorInitInfo& pInfo, int pAxis)
{
    return tryGetLocalAxis(pOut, *pInfo.getPlacementInfo(), pAxis);
}

bool tryGetLocalAxis(sead::Vector3f* pOut, const PlacementInfo& pInfo, int pAxis)
{
    if (pAxis == 0)
        return tryGetSide(pOut, pInfo);
    if (pAxis == 1)
        return tryGetUp(pOut, pInfo);
    if (pAxis == 2)
        return tryGetFront(pOut, pInfo);

    return false;
}

} // namespace al
