#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

const sead::Vector3f& getVelocity(const LiveActor* actor);
sead::Vector3f* getVelocityPtr(LiveActor* actor);

void setVelocity(LiveActor* actor, const sead::Vector3f& velocity);
void setVelocity(LiveActor* actor, float x, float y, float z);
void setVelocityX(LiveActor* actor, float x);
void setVelocityY(LiveActor* actor, float y);

// ???
void setVelocityZero(LiveActor* actor);
void setVelocityJump(LiveActor* actor, float);
void setVelocityToDirection(LiveActor* actor, const sead::Vector3f&, float);
void setVelocityToGravity(LiveActor* actor, float gravity);
void addVelocityToGravity(LiveActor* actor, float);

float calcSpeed(const LiveActor* actor);
float calcSpeedH(const LiveActor* actor);
float calcSpeedV(const LiveActor* actor);

} // namespace al
