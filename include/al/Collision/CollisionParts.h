#pragma once

#include <basis/seadTypes.h>

namespace al {

class LiveActor;

class CollisionParts;

void validateCollisionParts(LiveActor* pActor);
void invalidateCollisionParts(LiveActor* pActor);

bool isOnGround(const LiveActor* pActor, u32, float);

} // namespace al