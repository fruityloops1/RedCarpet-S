#pragma once

namespace al {

class LiveActor;

bool isDead(const LiveActor* actor);
bool isClipped(const LiveActor* actor);

void onCollide(LiveActor* actor);
void offCollide(LiveActor* actor);

} // namespace al
