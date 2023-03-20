#include "al/Placement/PlacementInfo.h"

namespace al {

PlacementInfo::PlacementInfo() = default;

void PlacementInfo::set(const ByamlIter& pPlacementIter, const ByamlIter& pUnitConfigIter, PlacementInfo* pInfo, s32 pInt)
{
    mPlacementIter = pPlacementIter;
    mUnitConfigIter = pUnitConfigIter;
    _20 = pInfo;
    _28 = pInt;
}

} // namespace al
