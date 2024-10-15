#pragma once

namespace al {

class LiveActor;
class Resource;

bool isExistModelResource(const LiveActor* actor);
bool isExistAnimResource(const LiveActor* actor);
bool isExistAnimResourceYaml(const LiveActor* actor, const char*, const char*);
al::Resource* getModelResource(const LiveActor* actor);

} // namespace al
