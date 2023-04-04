#pragma once

namespace al {

class LiveActor;

bool isDead(const LiveActor* pActor);
bool isClipped(const LiveActor* pActor);

void onCollide(LiveActor* pActor);
void offCollide(LiveActor* pActor);

} // namespace al
