#pragma once

#include <container/seadPtrArray.h>

namespace al {

class ScreenPointTarget;

class ScreenPointKeeper {
    sead::PtrArray<ScreenPointTarget> mScreenPointTargets; // warning: may not be a PtrArray (not checked)
};

} // namespace al
