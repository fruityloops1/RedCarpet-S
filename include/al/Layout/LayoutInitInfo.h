#pragma once

namespace al {

class LayoutActor;
class LayoutInitInfo;

void initLayoutActor(LayoutActor* pActor, const LayoutInitInfo& pInfo, const char* pArchive, const char* pSuffix);

} // namespace al
