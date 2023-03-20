#pragma once

#include "al/Base/Types.h"

namespace al {

class PlacementInfo;

class PlacementHolder {
    const char* _0 = nullptr;
    const char* _8 = nullptr;
    const char* _10 = nullptr;
    const char* _18 = nullptr;
    s32 _20;
    s32 _24 = -1;

public:
    PlacementHolder();

    void init(const PlacementInfo& pInfo);
};

} // namespace al
