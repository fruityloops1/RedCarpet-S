#pragma once

#include <container/seadPtrArray.h>

namespace al {

class LiveActor;
class ActorInitInfo;

class SubActorKeeper {
    LiveActor* const mParent = nullptr;
    s32 mCapacity = 0;
    s32 mSize = 0;
    LiveActor** mActors = nullptr;

public:
    SubActorKeeper(al::LiveActor* pActor, const al::ActorInitInfo& pInfo, const char*, int);

    static SubActorKeeper* tryCreate(al::LiveActor* pActor, const al::ActorInitInfo& pInfo, const char*, int);
};

void initSubActorKeeperNoFile(LiveActor* pActor, const ActorInitInfo& pInfo, int);

LiveActor* getSubActor(const LiveActor*, int pIdx);
LiveActor* getSubActor(const LiveActor* pActor, const char* pSubActorName);
LiveActor* tryGetSubActor(const LiveActor* pActor, const char* pSubActorName);
int getSubActorNum(const LiveActor* pActor);

void registerSubActorSyncClipping(LiveActor* pParent, LiveActor* pSub, u64 = 0);

} // namespace al
