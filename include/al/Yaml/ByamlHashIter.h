#pragma once

#include "al/Base/Types.h"

namespace al {

class ByamlData;
enum class ByamlDataType : u8;

class ByamlHashPair {
    u32 mKeyAndType;
    u32 mValue;

public:
    ByamlDataType getType() const { return ByamlDataType(mKeyAndType >> 24); }
    u32 getKeyIndex() const { return mKeyAndType & 0xFFFFFF; }
    u32 getValue() const { return mValue; }
};

class ByamlHashIter {
    struct Header {
        al::ByamlDataType type : 8;
        u32 hashAmount : 24;
    };

    union {
        const u8* mData;
        uintptr_t mDataPtr;
        const Header* mHeader;
    };

    const ByamlHashPair* getPairTable() const { return !mDataPtr ? nullptr : reinterpret_cast<ByamlHashPair*>(mDataPtr + sizeof(mDataPtr)); }
    u32 getSize() const { return mHeader->hashAmount; }

public:
    ByamlHashIter(const u8* pData);

    const ByamlHashPair* findPair(int pIdx) const;
    const ByamlHashPair* getPairByIndex(int pIdx) const;
    bool getDataByIndex(ByamlData* pData, s32 pIdx);
    bool getDataByKey(ByamlData* out, int index) const;
};

} // namespace al
