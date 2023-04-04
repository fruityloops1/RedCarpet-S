#pragma once

#include "al/LiveActor/LiveActor.h"

class Lighthouse;

class GoalItem : public al::LiveActor {
    u8 _148[0x24];
    int mScenarioID;
    u8 _170[0xbc];
    Lighthouse* mLighthouse;

public:
    GoalItem(const char* pName);
};
