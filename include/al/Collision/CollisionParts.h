#pragma once

#include <basis/seadTypes.h>

namespace al {

class LiveActor;

class CollisionParts;

void validateCollisionParts(LiveActor* actor);
void invalidateCollisionParts(LiveActor* actor);

bool isOnGround(const LiveActor* actor, u32, float);

} // namespace al