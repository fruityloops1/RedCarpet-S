#pragma once

#include "al/LiveActor/LiveActor.h"

class Coin : public al::LiveActor {
    u8 _148[0x40];

public:
    Coin();
    Coin(const char* pName);

    void kill() override;
};
