#include "al/Yaml/ByamlArrayIter.h"
#include "al/Yaml/ByamlData.h"
#include "al/Yaml/ByamlHashIter.h"
#include "al/Yaml/ByamlIter.h"
#include "al/Yaml/ByamlStringTableIter.h"

namespace al {

ByamlIter::ByamlIter() = default;

ByamlIter::ByamlIter(const u8* pData)
    : mData(pData)
    , mRootNode(nullptr)
{
    if (!mData)
        return;

    if (alByamlLocalUtil::verifiByaml(pData)) {
        int offset = mHeader->mDataOffset;
        if (offset != 0)
            mRootNode = mData + this->mHeader->mDataOffset;
    } else {
        mData = nullptr;
        mRootNode = nullptr;
    }
}

ByamlIter::ByamlIter(const u8* pData, const u8* pRootNode)
    : mData(pData)
    , mRootNode(pRootNode)
{
}

s32 ByamlIter::getSize() const
{
    if (isTypeContainer())
        return mContainerHeader->getCount();
    return 0;
}

bool ByamlIter::isTypeArray() const { return mContainerHeader != nullptr && mContainerHeader->getType() == ByamlDataType::Array; }
bool ByamlIter::isTypeHash() const { return mContainerHeader != nullptr && mContainerHeader->getType() == ByamlDataType::Hash; }
bool ByamlIter::isTypeContainer() const { return mContainerHeader != nullptr && (mContainerHeader->getType() == ByamlDataType::Array || mContainerHeader->getType() == ByamlDataType::Hash); }

bool ByamlIter::isExistKey(const char* pKey) const
{
    if (isTypeHash()) {
        ByamlStringTableIter stringIter(mData + mHeader->mHashKeyOffset);
        s32 idx = stringIter.findStringIndex(pKey);
        if (idx > -1) {
            ByamlHashIter hashIter(mRootNode);
            return hashIter.findPair(idx) != nullptr;
        }
    }
    return false;
}

int ByamlIter::getKeyIndex(const char* key) const
{
    ByamlStringTableIter iter(mData + mHeader->mHashKeyOffset);
    return iter.findStringIndex(key);
}

bool ByamlIter::getKeyName(const char** pOut, s32 pIdx) const
{
    if (!mRootNode)
        return false;

    if (!isTypeHash())
        return false;

    ByamlHashIter hashIter(mRootNode);
    const ByamlHashPair* pair = hashIter.getPairByIndex(pIdx);

    if (!pair)
        return false;

    ByamlStringTableIter stringIter(mData + mHeader->mHashKeyOffset);
    *pOut = stringIter.getString(pair->getKeyIndex());
    return true;
}

bool ByamlIter::getByamlDataByIndex(ByamlData* pOut, s32 pIdx) const
{
    if (isTypeArray()) {
        ByamlArrayIter arrayIter(mRootNode);
        return arrayIter.getDataByIndex(pOut, pIdx);
    } else if (isTypeHash()) {
        ByamlHashIter hashIter(mRootNode);
        return hashIter.getDataByIndex(pOut, pIdx);
    }

    return false;
}

bool ByamlIter::getByamlDataByKey(ByamlData* pOut, const char* pKey) const
{
    if (isTypeHash()) {
        int keyIdx = getKeyIndex(pKey);
        if (keyIdx > -1) {
            ByamlHashIter hashIter(mRootNode);
            return hashIter.getDataByKey(pOut, keyIdx);
        }
    }
    return false;
}

bool ByamlIter::getByamlDataAndKeyName(ByamlData* pOut, const char** pKey, s32 pIdx) const
{
    if (!isTypeHash())
        return false;

    ByamlHashIter hashIter(mRootNode);
    const ByamlHashPair* pair = hashIter.getPairByIndex(pIdx);

    if (!pair)
        return false;

    if (pOut)
        pOut->set(pair);

    ByamlStringTableIter stringIter(mData + mHeader->mHashKeyOffset);
    *pKey = stringIter.getString(pair->getKeyIndex());
    return true;
}

ByamlIter ByamlIter::getIterFromData(const ByamlData& pData) const
{
    if (pData.getType() == ByamlDataType::Hash || pData.getType() == ByamlDataType::Array)
        return ByamlIter(mData, &mData[pData.getUIntValue()]);
    if (pData.getType() == ByamlDataType::Null)
        return ByamlIter(mData, nullptr);
    return ByamlIter();
}

#ifdef NON_MATCHING
ByamlIter ByamlIter::getIterByIndex(s32 pIdx) const
{
    ByamlData data;
    if (!getByamlDataByIndex(&data, pIdx))
        return ByamlIter();

    return getIterFromData(data);
}

ByamlIter ByamlIter::getIterByKey(const char* pKey) const
{
    ByamlData data;
    if (!getByamlDataByKey(&data, pKey))
        return ByamlIter();

    return getIterFromData(data);
}

bool ByamlIter::tryGetIterByIndex(ByamlIter* pOut, s32 pIdx) const
{
    *pOut = getIterByIndex(pIdx);
    return pOut->isValid();
}

bool ByamlIter::tryGetIterByKey(ByamlIter* pOut, const char* pKey) const
{
    *pOut = getIterByKey(pKey);
    return pOut->isValid();
}

bool ByamlIter::tryGetIterAndKeyNameByIndex(ByamlIter* pOut, const char** pKey, s32 pIdx) const
{
    ByamlData data;
    if (!getByamlDataAndKeyName(&data, pKey, pIdx)) {
        *pKey = nullptr;
        return tryGetIterByIndex(pOut, pIdx);
    }

    *pOut = getIterFromData(data);
    return true;
}
#endif

bool ByamlIter::tryGetBoolByIndex(bool* pOut, s32 pIdx) const
{
    ByamlData data;
    if (!getByamlDataByIndex(&data, pIdx))
        return false;

    return tryConvertBool(pOut, &data);
}

bool ByamlIter::tryGetBoolByKey(bool* pOut, const char* pKey) const
{
    ByamlData data;

    if (getByamlDataByKey(&data, pKey))
        return tryConvertBool(pOut, &data);
    return false;
}

bool ByamlIter::tryGetStringByIndex(const char** pOut, s32 pIdx) const
{
    ByamlData data;
    if (!getByamlDataByIndex(&data, pIdx))
        return false;

    return tryConvertString(pOut, &data);
}

bool ByamlIter::tryGetStringByKey(const char** pOut, const char* pKey) const
{
    ByamlData data;

    if (getByamlDataByKey(&data, pKey))
        return tryConvertString(pOut, &data);
    return false;
}

bool ByamlIter::tryGetIntByIndex(s32* pOut, s32 pIdx) const
{
    ByamlData data;
    if (!getByamlDataByIndex(&data, pIdx))
        return false;

    return tryConvertInt(pOut, &data);
}

bool ByamlIter::tryGetIntByKey(s32* pOut, const char* pKey) const
{
    ByamlData data;

    if (getByamlDataByKey(&data, pKey))
        return tryConvertInt(pOut, &data);
    return false;
}

bool ByamlIter::tryGetFloatByIndex(float* pOut, s32 pIdx) const
{
    ByamlData data;
    if (!getByamlDataByIndex(&data, pIdx))
        return false;

    return tryConvertFloat(pOut, &data);
}

bool ByamlIter::tryGetFloatByKey(float* pOut, const char* pKey) const
{
    ByamlData data;

    if (getByamlDataByKey(&data, pKey))
        return tryConvertFloat(pOut, &data);
    return false;
}

bool ByamlIter::tryConvertString(const char** pOut, const ByamlData* pData) const
{

    if (pData->getType() == ByamlDataType::String) {
        ByamlStringTableIter stringIter(mData + mHeader->mStringTableOffset);
        *pOut = stringIter.getString(pData->getIntValue());
        return true;
    }
    return false;
}

bool ByamlIter::tryConvertBool(bool* pOut, const ByamlData* pData) const
{
    if (pData->getType() == ByamlDataType::Bool) {
        *pOut = pData->getIntValue() != 0;
        return true;
    }
    return false;
}

bool ByamlIter::tryConvertInt(s32* pOut, const ByamlData* pData) const
{
    if (pData->getType() == ByamlDataType::Int) {
        *pOut = pData->getIntValue();
        return true;
    }
    return false;
}

bool ByamlIter::tryConvertFloat(float* pOut, const ByamlData* pData) const
{
    if (pData->getType() == ByamlDataType::Float) {
        *pOut = pData->getFloatValue();
        return true;
    }
    return false;
}

} // namespace al
