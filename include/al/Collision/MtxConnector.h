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
    MtxConnector(const sead::Quatf& pQuat, const sead::Vector3f& pTrans);
};

MtxConnector* tryCreateMtxConnector(LiveActor* pActor, const ActorInitInfo& pInfo);

void attachMtxConnectorToCollision(MtxConnector* pConnector, const LiveActor* pActor, bool);
void connectPoseQT(LiveActor* pActor, const MtxConnector* pConnector);

} // namespace al