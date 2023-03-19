#pragma once

#include "al/Yaml/ByamlContainerHeader.h"
#include "al/Yaml/ByamlData.h"

namespace al {

class ByamlContainerHeader {
    union {
        u32 mSize;
        u8 mType;
    };

public:
    inline ByamlDataType getType() const { return (ByamlDataType)mType; }
    inline u32 getCount() const { return mSize >> 8; }
};

} // namespace al
