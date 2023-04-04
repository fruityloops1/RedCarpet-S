#pragma once

#include "al/Layout/LayoutActor.h"
#include "al/Layout/LayoutInitInfo.h"

class WindowProcessing : public al::LayoutActor {
    u8 _119[0x8];
    int mProcessFrames;
    void* _128 = nullptr;

public:
    WindowProcessing(const al::LayoutInitInfo& pInfo, const char* = nullptr);

    void appearWithSystemMessage(const char* pMessageBinary, const char* pMsg, int pNumFrames, bool);
};
