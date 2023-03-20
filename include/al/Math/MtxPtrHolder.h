#pragma once

#include <math/seadMatrix.h>

namespace al {

class MtxPtrHolder {
    void* _0 = nullptr;
    void* _8 = nullptr;
    void* _10 = nullptr;

public:
    MtxPtrHolder();

    void init(s32);
    void setMtxPtrAndName(int, const char*, const sead::Matrix34f*);
    sead::Matrix34f* tryFindMtxPtr(const char*) const;
};

} // namespace al
