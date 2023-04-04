#pragma once

#include <container/seadPtrArray.h>

namespace al {

class HitSensor;

class HitSensorKeeper {
    sead::PtrArray<HitSensor> mHitSensors;

public:
};

} // namespace al
