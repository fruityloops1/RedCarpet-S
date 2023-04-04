#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

const sead::Vector3f& getVelocity(const LiveActor* pActor);
sead::Vector3f* getVelocityPtr(LiveActor* pActor);

void setVelocity(LiveActor* pActor, const sead::Vector3f& pVelocity);
void setVelocity(LiveActor* pActor, float x, float y, float z);
void setVelocityX(LiveActor* pActor, float x);
void setVelocityY(LiveActor* pActor, float y);

// ???
void setVelocityZero(LiveActor* pActor);
void setVelocityJump(LiveActor* pActor, float);
void setVelocityToDirection(LiveActor* pActor, const sead::Vector3f&, float);
void setVelocityToGravity(LiveActor* pActor, float pGravity);
void addVelocityToGravity(LiveActor* pActor, float);

float calcSpeed(const LiveActor* pActor);
float calcSpeedH(const LiveActor* pActor);
float calcSpeedV(const LiveActor* pActor);

} // namespace al
