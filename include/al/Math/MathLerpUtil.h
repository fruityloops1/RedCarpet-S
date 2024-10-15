#pragma once

#include <math/seadVectorFwd.h>

namespace al {

float lerpValue(float min, float max, float amount);

void lerpVec(sead::Vector3f* out, const sead::Vector3f& min, const sead::Vector3f& max, float amount);

} // namespace al
