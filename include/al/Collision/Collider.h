#pragma once

#include "al/Collision/CollisionDirector.h"
#include <math/seadMatrix.h>
#include <math/seadVector.h>

namespace al {

class LiveActor;

class Collider : IUseCollision {
    CollisionDirector* mCollisionDirector = nullptr;
    u64 _10[2];
    sead::Matrix34f* _20;
    sead::Vector3f* _28[2];
    float mRadius;
    float mYOffset;
    u8 unk4[0x248];

public:
};

float getColliderRadius(const LiveActor* actor);
float getColliderOffsetY(const LiveActor* actor);

} // namespace al