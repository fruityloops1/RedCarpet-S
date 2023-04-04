#pragma once

#include "al/Scene/ISceneObj.h"

class WindowMessage;

class GuideGameWindow : public al::ISceneObj {
    void* _8;

public:
    WindowMessage* mWindow = nullptr;

    const char* getSceneObjName() const override; // ガイドウィンドウ
};
