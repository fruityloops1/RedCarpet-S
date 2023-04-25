#include "al/Base/Base.h"

namespace al {

u32 calcHashCode(const char* pStr)
{
    u32 result = 0;
    char curChar = *pStr;

    while ((curChar = *pStr)) {
        result = result * 31 + curChar;
        pStr++;
    }

    return result;
}

} // namespace al
