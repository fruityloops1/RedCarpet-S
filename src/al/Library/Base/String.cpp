#include "al/Base/String.h"
#include <prim/seadMemUtil.h>

namespace al {

bool isInStack(const void* pPtr)
{
    return sead::MemUtil::isStack(pPtr);
}

bool isEqualString(const char* pStr1, const char* pStr2)
{
    char val2 = *pStr2++, val1 = *pStr1++;
    while (val1 == val2) {
        if (val1 == '\0')
            return true;
        val2 = *pStr2++;
        val1 = *pStr1++;
    }
    return false;
}

bool isEqualString(const sead::SafeString& pStr1, const sead::SafeString& pStr2)
{
    return isEqualString(pStr1.cstr(), pStr2.cstr());
}

} // namespace al
