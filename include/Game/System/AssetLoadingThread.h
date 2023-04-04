#pragma once

#include <heap/seadDisposer.h>

namespace rc {

class AssetLoadingThread {
    SEAD_SINGLETON_DISPOSER(AssetLoadingThread);

public:
    enum class LOAD_TYPE : u32 { // idk if this is Right.
        SingleMode,
        SM3DW
    };

    void cancelAndDelete3DWorldStationed();
    void disableFastLoad(bool);
    void startLoad(LOAD_TYPE);
};

} // namespace rc
