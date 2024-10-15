#pragma once

#include <math/seadVectorFwd.h>

namespace al {

class LiveActor;

void calcJointPos(sead::Vector3f* out, const LiveActor* actor, const char* jointName);

} // namespace al
