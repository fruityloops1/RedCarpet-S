#pragma once

#include "al/Base/Types.h"
#include "al/Yaml/ByamlContainerHeader.h"
#include "al/Yaml/ByamlData.h"
#include "al/Yaml/ByamlHeader.h"

namespace al {

class ByamlIter {
    union {
        const u8* mData = nullptr;
        const ByamlHeader* mHeader;
    };
    union {
        const u8* mRootNode = nullptr;
        const ByamlContainerHeader* mContainerHeader;
    };

public:
    ByamlIter();
    ByamlIter(const u8* pData);
    ByamlIter(const u8* pData, const u8* pRootNode);
    ByamlIter(const ByamlIter& pOther);

    bool isEqualData(const ByamlIter& other) const;

    bool isValid() const;
    bool isTypeArray() const;
    bool isTypeHash() const;
    bool isTypeContainer() const;

    s32 getSize() const;

    bool isExistKey(const char* pKey) const;
    s32 getKeyIndex(const char* pKey) const;
    bool getKeyName(const char** pOut, s32 pIdx) const;

    bool getByamlDataByIndex(ByamlData* pOut, s32 pIdx) const;
    bool getByamlDataByKey(ByamlData* pOut, const char* pKey) const;
    bool getByamlDataByKeyIndex(ByamlData* pOut, s32 pIdx) const;
    bool getByamlDataAndKeyName(ByamlData* pOut, const char** pKey, s32 pIdx) const;

    bool tryGetStringByIndex(const char** pOut, s32 pIdx) const;
    bool tryGetStringByKey(const char** pOut, const char* pKey) const;
    bool tryGetBinaryByIndex(const u8** pOut, s32* size, s32 pIdx) const;
    bool tryGetBinaryByKey(const u8** pOut, s32* size, const char* pKey) const;
    ByamlIter getIterFromData(const ByamlData& pData) const;
    ByamlIter getIterByIndex(s32 pIdx) const;
    bool tryGetIterByIndex(ByamlIter* pOut, s32 pIdx) const;
    ByamlIter getIterByKey(const char* pKey) const;
    bool tryGetIterByKey(ByamlIter* pOut, const char* pKey) const;
    bool tryGetIterAndKeyNameByIndex(ByamlIter* pOut, const char** pKey, s32 pIdx) const;
    bool tryGetBoolByIndex(bool* pOut, s32 pIdx) const;
    bool tryGetBoolByKey(bool* pOut, const char* pKey) const;
    bool tryGetIntByIndex(s32* pOut, s32 pIdx) const;
    bool tryGetIntByKey(s32* pOut, const char* pKey) const;
    bool tryGetFloatByIndex(float* pOut, s32 pIdx) const;
    bool tryGetFloatByKey(float* pOut, const char* pKey) const;
    bool tryGetUIntByIndex(u32* pOut, s32 pIdx) const;
    bool tryGetUIntByKey(u32* pOut, const char* pKey) const;

    bool tryConvertString(const char** pOut, const ByamlData* pData) const;
    bool tryConvertBinary(const u8** pOut, s32* size, const ByamlData* pData) const;
    bool tryConvertIter(ByamlIter* iter, const ByamlData* pData) const;
    bool tryConvertBool(bool* pOut, const ByamlData* pData) const;
    bool tryConvertInt(s32* pOut, const ByamlData* pData) const;
    bool tryConvertFloat(float* pOut, const ByamlData* pData) const;
    bool tryConvertUInt(u32* pOut, const ByamlData* pData) const;

    void set(const ByamlIter& pOther)
    {
        mData = pOther.mData;
        mRootNode = pOther.mRootNode;
    }

    const ByamlHeader* getHeader() const { return mHeader; }
};

} // namespace al
