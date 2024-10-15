#pragma once

#include "al/Yaml/ByamlIter.h"
namespace al {

template <typename Creator>
struct NameToCreator {
    const char* name;
    Creator creator;
};

template <typename T>
class Factory {
    const char* mName = nullptr;
    al::NameToCreator<T>* mEntries = nullptr;
    int mEntryAmount = 0;
    u8 _14[0xC];
    al::ByamlIter mCreatorToClassNameTable;

public:
    inline Factory(const char* factoryName)
        : mName(factoryName)
        , mEntries(nullptr)
        , mEntryAmount(0)
    {
    }
    template <int N>
    inline Factory(const char* factoryName, al::NameToCreator<T> (&entries)[N])
        : mName(factoryName)
    {
        initFactory(entries);
    }
    template <int N>
    inline void initFactory(al::NameToCreator<T> (&entries)[N])
    {
        mEntries = entries;
        mEntryAmount = N;
    }

    virtual const char* convertName(const char* pObjectName) const; // 3D Land leftover
};

} // namespace al
