#pragma once

#include <basis/seadTypes.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {

class ActorInitInfo;
class LiveActor;

class MtxConnector {
    u8 _0[0x5c];

public:
    MtxConnector(const sead::Quatf& quat, const sead::Vector3f& trans);
};

MtxConnector* tryCreateMtxConnector(LiveActor* actor, const ActorInitInfo& info);

void attachMtxConnectorToCollision(MtxConnector* connector, const LiveActor* actor, bool);
void connectPoseQT(LiveActor* actor, const MtxConnector* connector);

} // namespace al