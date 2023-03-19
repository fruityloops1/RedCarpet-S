#pragma once

#include "al/Base/Types.h"

namespace al {

struct ByamlHeader {
    const u16 mTag;
    const u16 mVersion;
    const u32 mHashKeyOffset;
    const u32 mStringTableOffset;
    const u32 mDataOffset;
};

} // namespace al

namespace alByamlLocalUtil {

bool verifiByaml(const u8* data);

} // namespace alByamlLocalUtil
