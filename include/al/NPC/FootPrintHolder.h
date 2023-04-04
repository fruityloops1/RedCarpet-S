#pragma once

#include "al/Yaml/ByamlIter.h"

namespace al {

class LiveActor;

class FootPrintServer;
class FootPrintHolder {
    FootPrintServer* _0 = nullptr;
    void* _8 = nullptr;
    LiveActor* mParent = nullptr;
    ByamlIter* _18 = nullptr;
    u8 _20[0x20];
    const char* mPlayerName = nullptr;
    void* _48 = nullptr;

public:
    FootPrintHolder(LiveActor*, const char*, FootPrintServer*);

    const char* getPlayerName() const { return mPlayerName; }
};

} // namespace al
