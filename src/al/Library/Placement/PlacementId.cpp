#include "al/Placement/PlacementId.h"
#include "al/Placement/PlacementInfo.h"

#include "Game/System/GameDataHolder.h"

namespace al {

PlacementId::PlacementId() = default;
PlacementId::PlacementId(const char* pPlacementId, const char* pLayerConfigName, const char* pUnitConfigName, const char* pUnitConfigId)
    : mPlacementId(pPlacementId)
    , mLayerConfigName(pLayerConfigName)
    , mUnitConfigName(pUnitConfigName)
    , mUnitConfigId(pUnitConfigId)
{
}

void PlacementId::init(const PlacementInfo& pInfo)
{
    mPlacementId = nullptr;
    mCommonId = nullptr;
    mUnitConfigId = nullptr;
    mUnitConfigName = nullptr;
    mLayerConfigName = nullptr;
    pInfo.getPlacementIter().tryGetStringByKey(&mCommonId, "CommonId");
    pInfo.getPlacementIter().tryGetStringByKey(&mLayerConfigName, "LayerConfigName");
    pInfo.getZoneIter().tryGetStringByKey(&mUnitConfigName, "UnitConfigName");
    pInfo.getZoneIter().tryGetStringByKey(&mUnitConfigId, "Id");
    pInfo.getPlacementIter().tryGetStringByKey(&mPlacementId, "Id");
}

// PlacementId::isEqual

} // namespace al
