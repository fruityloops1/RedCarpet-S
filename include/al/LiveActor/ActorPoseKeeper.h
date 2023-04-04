#pragma once

#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

namespace al {

class ActorPoseKeeperBase {
    sead::Vector3f mTrans { 0, 0, 0 };

public:
    ActorPoseKeeperBase() = default;

    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Vector3f& getFront() const;
    virtual const sead::Quatf& getQuat() const;
    virtual const sead::Vector3f& getGravity() const;
    virtual const sead::Matrix34f getMtx() const;

    virtual sead::Vector3f* getRotatePtr() const;
    virtual sead::Vector3f* getScalePtr() const;
    virtual sead::Vector3f* getVelocityPtr() const;
    virtual sead::Vector3f* getFrontPtr() const;
    virtual sead::Quatf* getQuatPtr() const;
    virtual sead::Vector3f* getGravityPtr() const;
    virtual sead::Matrix34f getMtxPtr() const;

    virtual void updatePoseRotate(const sead::Vector3f& rotate);
    virtual void updatePoseQuat(const sead::Quatf& quat);
    virtual void updatePoseMtx(const sead::Matrix34f& mtx);
    virtual void copyPose(const ActorPoseKeeperBase*);
    virtual void calcBaseMtx(sead::Matrix34f* mtx);
};

} // namespace al
