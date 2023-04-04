#pragma once

#include "al/Base/Types.h"
#include <prim/seadSafeString.h>

namespace al {

class MatchStr;

const char* getBaseName(const char* pPath);
const char* createStringIfInStack(const char* pStr);
const char* createConcatString(const char* pStr1, const char* pStr2);
const u8* getSubStringUnmatched(const char* pStr, const MatchStr& pMatchStr);
void removeExtensionString(char* pBuffer, u32 pBufferSize, const char* pStr);
void removeStringFromEnd(char* pBuffer, u32 pBufferSize, const char* pSuffix, const char* pStr);
bool isEqualSubString(const char* pStr, const char* pSubString);
bool isEqualSubString(const sead::SafeString& pStr, const sead::SafeString& pSubString);
bool isStartWithString(const char* pStr, const char* pPrefix);
bool isEndWithString(const char* pStr, const char* pSuffix);
bool isMatchString(const char* pStr, const MatchStr& pMatchStr);
s32 compareStringIgnoreCase(const char* pStr1, const char* pStr2);
void copyString(char* pOutStr, const char* pFromStr, u32 pMaxLen);
bool isInStack(const void* pPtr) NO_INLINE;
bool isEqualString(const char* pStr1, const char* pStr2) NO_INLINE;
bool isEqualString(const sead::SafeString& pStr1, const sead::SafeString& pStr2);
bool isEqualStringCase(const char* pStr1, const char* pStr2);

template <s32 L>
class StringTmp : public sead::FixedSafeString<L> {
public:
    StringTmp(const char* format, ...)
        : sead::FixedSafeString<L>()
    {
        std::va_list args;
        va_start(args, format);
        this->formatV(format, args);
        va_end(args);
    }
    ~StringTmp() = default;
};

} // namespace al
