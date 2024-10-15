#pragma once

#include "al/Base/Types.h"
#include <prim/seadSafeString.h>

namespace al {

class MatchStr;

const char* getBaseName(const char* path);
const char* createStringIfInStack(const char* str);
const char* createConcatString(const char* str1, const char* str2);
const u8* getSubStringUnmatched(const char* str, const MatchStr& matchStr);
void removeExtensionString(char* pBuffer, u32 pBufferSize, const char* str);
void removeStringFromEnd(char* pBuffer, u32 pBufferSize, const char* suffix, const char* str);
bool isEqualSubString(const char* str, const char* subString);
bool isEqualSubString(const sead::SafeString& str, const sead::SafeString& subString);
bool isStartWithString(const char* str, const char* prefix);
bool isEndWithString(const char* str, const char* suffix);
bool isMatchString(const char* str, const MatchStr& matchStr);
s32 compareStringIgnoreCase(const char* str1, const char* str2);
void copyString(char* outStr, const char* fromStr, u32 maxLen);
bool isInStack(const void* ptr) NO_INLINE;
bool isEqualString(const char* str1, const char* str2) NO_INLINE;
bool isEqualString(const sead::SafeString& str1, const sead::SafeString& str2);
bool isEqualStringCase(const char* str1, const char* str2);

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
