#pragma once

#include "al/Yaml/ByamlData.h"

namespace al {

class ByamlStringTableIter {
    struct Header {
        const ByamlDataType type : 8;
        const u32 stringAmount : 24;
    };

    union {
        const u8* mData;
        uintptr_t mDataPtr;
        const Header* mHeader;
    };

public:
    ByamlStringTableIter(const u8* pData);
    const u32* getAddressTable() const { return reinterpret_cast<u32*>(mDataPtr + sizeof(mDataPtr)); }

    const char* getString(s32 pIdx) const;
    s32 findStringIndex(const char* pStr) const;
};

} // namespace al
