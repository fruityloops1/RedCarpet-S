#pragma once

#include <math/seadMatrix.h>
#include <math/seadVectorFwd.h>

namespace al {

class EffectSystemInfo;
class MtxPtrHolder;

class EffectKeeper {
    const char* mUserName = nullptr;
    void* _8 = nullptr;
    void* _10 = nullptr;
    const char* _18 = "";
    void* _20 = nullptr;
    void* _28 = nullptr;
    MtxPtrHolder* mMtxPtrHolder = nullptr;

public:
    EffectKeeper(const EffectSystemInfo*, const char* userName, const sead::Vector3f*, const sead::Vector3f*, const sead::Matrix34f*);
};

class IUseEffectKeeper {
public:
    virtual EffectKeeper* getEffectKeeper() const = 0;
};

void tryDeleteEffect(IUseEffectKeeper* user, const char* effectName);

} // namespace al
