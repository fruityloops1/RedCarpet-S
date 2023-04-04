#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/Rail/Rail.h"
#include "al/Rail/RailRider.h"

namespace al {

class RailKeeper {
    Rail* mRail = nullptr;
    RailRider* mRailRider = nullptr;

public:
    RailKeeper(const PlacementInfo& info);
};

} // namespace al
