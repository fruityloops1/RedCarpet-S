#pragma once

#include "al/LiveActor/LiveActor.h"

class Lighthouse : public al::LiveActor {
    u8 _328[0x68];
    int mNextScenarioID;

public:
    Lighthouse(const char* pName);
};
