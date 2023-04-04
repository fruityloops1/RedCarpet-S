#pragma once

#include "al/HitSensor/HitSensor.h"
#include "al/LiveActor/LiveActor.h"
#include "al/Resource/Resource.h"
#include <math/seadMatrix.h>

namespace al {

class CollisionObj : public al::LiveActor {
public:
    CollisionObj(const ActorInitInfo& pInfo, Resource* pResource, const char* pCollisionPartsName, HitSensor* pCollisionSensor, const sead::Matrix34f*, const char*);
};

CollisionObj* createCollisionObj(LiveActor* pResourceOwner, const ActorInitInfo& pInfo, const char* pCollisionPartsName, HitSensor* pCollisionSensor, const char* pCollisionFollowJointName, const char* = nullptr);

} // namespace al
