#pragma once

namespace al {

class LiveActor;
class ActorItemKeeper {
public:
    LiveActor* mParent;
}; // 0x38?

void appearItemTiming(const LiveActor* actor, const char* itemName);

} // namespace al