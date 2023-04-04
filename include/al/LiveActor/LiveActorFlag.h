#pragma once

namespace al {

class LiveActor;
struct LiveActorFlag {
    bool isDead = true;
    bool isClipped = false;
    bool flag3;
    bool isDraw;
    bool isClippedByLod;
    bool isOffCalcAnim;
    bool isHideModel = false;
    bool isColliderDisabled;
    bool flag9;
    bool flag10;
    bool isMaterialCode;
    bool isAreaTarget;
    bool isUpdateMovementEffectAudioCollisionSensor = true; // true?
};

} // namespace al
