#pragma once

#include "Game/Player/Player/PlayerFigureDirector.h"
#include <math/seadVector.h>

struct PlayerProperty {
    sead::Vector3f mTrans;
    u8 _C[0x18];
    sead::Vector3f mVelocity;
};

class Player {
    PlayerProperty* mPlayerProperty = nullptr;
    u8 _8[0x80];
    PlayerFigureDirector* mFigureDirector = nullptr;

public:
};