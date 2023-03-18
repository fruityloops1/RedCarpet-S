#pragma once

#include <prim/seadSafeString.h>

namespace al {

bool isInStack(const void* pPtr);
bool isEqualString(const char* pStr1, const char* pStr2);
bool isEqualString(const sead::SafeString& pStr1, const sead::SafeString& pStr2);

} // namespace al
