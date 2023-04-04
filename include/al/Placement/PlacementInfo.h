#pragma once

#include "al/Yaml/ByamlIter.h"

namespace al {

class PlacementInfo {
    ByamlIter mPlacementIter;
    ByamlIter mZoneIter;
    PlacementInfo* _20 = nullptr;
    s32 _28 = -1;

public:
    PlacementInfo();

    void set(const ByamlIter& pPlacementIter, const ByamlIter& pUnitConfigIter, PlacementInfo* pInfo, s32 pInt);

    const ByamlIter& getPlacementIter() const { return mPlacementIter; }
    const ByamlIter& getZoneIter() const { return mZoneIter; }

    PlacementInfo* get_20() const { return _20; }
    s32 get_28() const { return _28; }
};

} // namespace al