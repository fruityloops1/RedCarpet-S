#pragma once

#include <math/seadVectorFwd.h>

namespace al {

class LiveActor;

void calcJointPos(sead::Vector3f* pOut, const LiveActor* pActor, const char* pJointName);

} // namespace al
