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
    SubActorKeeper(al::LiveActor* actor, const al::ActorInitInfo& info, const char*, int);

    static SubActorKeeper* tryCreate(al::LiveActor* actor, const al::ActorInitInfo& info, const char*, int);
};

void initSubActorKeeperNoFile(LiveActor* actor, const ActorInitInfo& info, int);

LiveActor* getSubActor(const LiveActor*, int idx);
LiveActor* getSubActor(const LiveActor* actor, const char* subActorName);
LiveActor* tryGetSubActor(const LiveActor* actor, const char* subActorName);
int getSubActorNum(const LiveActor* actor);

void registerSubActorSyncClipping(LiveActor* parent, LiveActor* sub, u64 = 0);

} // namespace al
