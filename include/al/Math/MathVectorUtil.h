#pragma once

#include <math/seadQuat.h>
#include <math/seadVectorFwd.h>

namespace al {

void calcQuatSide(sead::Vector3f* pOut, const sead::Quatf& pQuat);
void calcQuatUp(sead::Vector3f* pOut, const sead::Quatf& pQuat);
void calcQuatFront(sead::Vector3f* pOut, const sead::Quatf& pQuat);

void rotateQuatXDirDegree(sead::Quatf* pOut, const sead::Quatf& pFrom, float pDegrees);
void rotateQuatYDirDegree(sead::Quatf* pOut, const sead::Quatf& pFrom, float pDegrees);
void rotateQuatZDirDegree(sead::Quatf* pOut, const sead::Quatf& pFrom, float pDegrees);

void rotateQuatRadian(sead::Quatf* pOut, const sead::Quatf& pFrom, const sead::Vector3f& pAxis, float pRadians);

} // namespace al
