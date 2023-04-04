#pragma once

namespace al {

class LiveActor;

class ActorPrePassLightKeeper;

void appearPrePassLight(const LiveActor* pActor, const char*, int);
void killPrePassLightAll(const LiveActor* pActor, int);

} // namespace al
