#pragma once

#include "Game/Ride/RaidonSurf.h"
#include "Game/Scene/InGameSceneBase.h"

class SingleModeScene : public InGameSceneBase {
    u8 _E1[0x18c];
    RaidonSurf* mRaidonSurf = nullptr;

public:
    void movement() override;
};
