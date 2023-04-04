#pragma once

#include <heap/seadHeapMgr.h>

namespace al {

class SceneHeapSetter : sead::ScopedCurrentHeapSetter {
    sead::Heap* _8;

public:
    SceneHeapSetter();
};

class MemorySystem;

void createSceneHeap(const char* pStageName);

sead::Heap* getSequenceHeap();

} // namespace al
