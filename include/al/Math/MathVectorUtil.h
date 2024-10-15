#pragma once

#include <math/seadQuat.h>
#include <math/seadVectorFwd.h>

namespace al {

void calcQuatSide(sead::Vector3f* out, const sead::Quatf& quat);
void calcQuatUp(sead::Vector3f* out, const sead::Quatf& quat);
void calcQuatFront(sead::Vector3f* out, const sead::Quatf& quat);

void rotateQuatXDirDegree(sead::Quatf* out, const sead::Quatf& from, float degrees);
void rotateQuatYDirDegree(sead::Quatf* out, const sead::Quatf& from, float degrees);
void rotateQuatZDirDegree(sead::Quatf* out, const sead::Quatf& from, float degrees);

void rotateQuatRadian(sead::Quatf* out, const sead::Quatf& from, const sead::Vector3f& axis, float radians);

} // namespace al
