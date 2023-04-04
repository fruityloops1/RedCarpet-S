#pragma once

namespace al {

class LiveActor;
class Resource;

bool isExistModelResource(const LiveActor* pActor);
bool isExistAnimResource(const LiveActor* pActor);
bool isExistAnimResourceYaml(const LiveActor* pActor, const char*, const char*);
al::Resource* getModelResource(const LiveActor* pActor);

} // namespace al
