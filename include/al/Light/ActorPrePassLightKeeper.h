#pragma once

namespace al {

class LiveActor;

class ActorPrePassLightKeeper;

void appearPrePassLight(const LiveActor* actor, const char*, int);
void killPrePassLightAll(const LiveActor* actor, int);

} // namespace al
