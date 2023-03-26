#pragma once

#include <math/seadVectorFwd.h>

namespace al {

class ByamlIter;

bool tryGetByamlV3f(sead::Vector3f* pOut, const ByamlIter& pIter);
bool tryGetByamlV3f(sead::Vector3f* pOut, const ByamlIter& pIter, const char* pHashName);

} // namespace al
