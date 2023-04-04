#pragma once

#include "al/Layout/LayoutActor.h"

namespace al {

class SimpleLayoutAppearWaitEnd : public al::LayoutActor {
public:
    SimpleLayoutAppearWaitEnd(const char* pName, const char* pLayoutName, const LayoutInitInfo& pInfo, const char*, bool pIsLocalized);
};

} // namespace al
