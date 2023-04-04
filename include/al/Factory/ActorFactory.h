#pragma once

#include "al/Factory/Factory.h"

namespace al {

class LiveActor;

using CreateActorFunctionType = al::LiveActor* (*)(const char*);
using ActorFactoryTableEntry = NameToCreator<CreateActorFunctionType>;

class ActorFactory : public Factory<CreateActorFunctionType> {
public:
    ActorFactory(const char* pName);
};

template <typename T>
LiveActor* createActorFunction(const char* pName);

} // namespace al
