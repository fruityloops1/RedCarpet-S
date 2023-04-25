#include "al/Base/String.h"
#include <cstdio>
#include <prim/seadMemUtil.h>

namespace al {

const char* getBaseName(const char* pPath)
{
    const char* slashPtr = std::strrchr(pPath, '/');
    return slashPtr ? slashPtr + 1 : pPath;
}

const char* createStringIfInStack(const char* pStr)
{
    if (!isInStack(pStr))
        return pStr;

    s32 bufSize = strlen(pStr) + 1;
    char* newStr = new char[bufSize];
    snprintf(newStr, bufSize, "%s", pStr);
    return newStr;
}

const char* createConcatString(const char* pStr1, const char* pStr2)
{
    s32 str1Len = std::strlen(pStr1), str2Len = std::strlen(pStr2);
    s32 bufSize = str1Len + str2Len + 1;

    char* newStr = new char[bufSize];
    snprintf(newStr, bufSize, "%s%s", pStr1, pStr2);
    return newStr;
}

void removeExtensionString(char* pBuffer, u32 pBufferSize, const char* pStr)
{
    std::snprintf(pBuffer, pBufferSize, "%s", pStr);

    char *lastPeriod = std::strrchr(pBuffer, '.'), *lastSlash = std::strrchr(pBuffer, '/');

    if (lastPeriod && lastPeriod >= lastSlash && lastSlash + 1 != lastPeriod)
        *lastPeriod = '\0';
}

void removeStringFromEnd(char* pBuffer, u32 pBufferSize, const char* pSuffix, const char* pStr)
{
    std::snprintf(pBuffer, pBufferSize, "%s", pStr);

    s32 strLen = std::strlen(pBuffer), suffixLen = std::strlen(pSuffix);

    if (suffixLen <= strLen)
        pBuffer[strLen - suffixLen] = '\0';
}

bool isEqualSubString(const char* pStr, const char* pSubString)
{
    return std::strstr(pStr, pSubString) != nullptr;
}

bool isEqualSubString(const sead::SafeString& pStr, const sead::SafeString& pSubString)
{
    return isEqualSubString(pStr.cstr(), pSubString.cstr());
}

bool isStartWithString(const char* pStr, const char* pPrefix)
{
    if (pPrefix[0] == '\0')
        return true;

    u8 val = pPrefix[0];
    const char* prefixIter = pPrefix + 1;

    while (*pStr && *pStr == val) {
        val = *prefixIter++;
        pStr++;
        if (val == '\0')
            return true;
    }

    return false;
}

bool isEndWithString(const char* pStr, const char* pSuffix)
{
    s32 strLen = std::strlen(pStr), suffixLen = std::strlen(pSuffix);
    if (strLen < suffixLen)
        return false;

    s32 suffixOffsetInStr = uintptr_t(strLen) - uintptr_t(suffixLen);

    return isEqualString(pStr + suffixOffsetInStr, pSuffix);
}

bool isMatchString(const char* pStr, const MatchStr& pMatchStr)
{
    const u8* data = getSubStringUnmatched(pStr, pMatchStr);

    return data ? *data == 0 : data != nullptr;
}

s32 compareStringIgnoreCase(const char* pStr1, const char* pStr2)
{
    return strcasecmp(pStr1, pStr2);
}

void copyString(char* pOutStr, const char* pFromStr, u32 pMaxLen)
{
    std::strncpy(pOutStr, pFromStr, pMaxLen);
}

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
    const char *pCStr1 = pStr1.cstr(), *pCStr2 = pStr2.cstr();
    char val2 = *pCStr2++, val1 = *pCStr1++;
    while (val1 == val2) {
        if (val1 == '\0')
            return true;
        val2 = *pCStr2++;
        val1 = *pCStr1++;
    }
    return false;
}

bool isEqualStringCase(const char* pStr1, const char* pStr2)
{
    return strcasecmp(pStr1, pStr2) == 0;
}

} // namespace al
