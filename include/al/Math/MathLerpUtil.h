#pragma once

#include <math/seadVectorFwd.h>

namespace al {

float lerpValue(float pMin, float pMax, float pAmount);

void lerpVec(sead::Vector3f* pOut, const sead::Vector3f& pMin, const sead::Vector3f& pMax, float pAmount);

} // namespace al
