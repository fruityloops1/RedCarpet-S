#pragma once

#include <prim/seadSafeString.h>

namespace al {

class IUseAudioKeeper;
class MeInfo;

void startSe(const IUseAudioKeeper* pUser, const sead::SafeString& pName, MeInfo*);
void setSeSeqLocalVariableDefault(const IUseAudioKeeper* pUser, int, int);

} // namespace al
