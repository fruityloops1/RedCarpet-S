#pragma once

#include "al/Factory/ActorFactory.h"

class ProjectActorFactory : public al::ActorFactory {

public:
    static al::ActorFactoryTableEntry sActorEntries[];

    ProjectActorFactory();

    const char* convertName(const char* pName) const override;
};
