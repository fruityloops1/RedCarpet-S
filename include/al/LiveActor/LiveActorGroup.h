#pragma once

#include <container/seadPtrArray.h>

namespace al {

class LiveActor;

class LiveActorGroup {
    const char* const mName = nullptr;
    s32 mCapacity = 0;
    s32 mSize = 0;
    LiveActor** mActors = nullptr;

public:
    LiveActorGroup(const char* pName, int pCapacity);
    virtual void registerActor(LiveActor* pActor);
};

} // namespace al
