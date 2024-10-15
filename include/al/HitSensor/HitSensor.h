#pragma once

#include <math/seadMatrix.h>
#include <math/seadVectorFwd.h>

namespace al {

class LiveActor;

class HitSensor {
    const char* const mName = nullptr;
    u8 _8[0x38];
    al::LiveActor* mHostActor = nullptr;
    const sead::Vector3f* mFollowPos = nullptr;
    const sead::Matrix34f* mFollowMtx = nullptr;

public:
    HitSensor(al::LiveActor* host, const char* name, unsigned int, float, unsigned short, const sead::Vector3f*, const sead::Matrix34f*, const sead::Vector3f&);

    bool trySensorSort();
    void setFollowPosPtr(const sead::Vector3f*);
    void setFollowMtxPtr(const sead::Matrix34f*);
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();
    void update();
    void addHitSensor(al::HitSensor* sensor);
};

} // namespace al
