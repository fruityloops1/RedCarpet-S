#pragma once

#include "al/LiveActor/LiveActor.h"

class PlayerModel : public al::LiveActor {
    void* _148 = nullptr;
    const char* mPlayerName = nullptr;
    const char* mFigureName = nullptr;
    u8 _160[0x80];

public:
    PlayerModel(const char* pName, const char* pArchiveName, const al::ActorInitInfo& pInfo, const char* pSuffix);
};
