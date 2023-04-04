#pragma once

#include "nn/types.h"

class ErrorViewer {
    u8 _0[0x30];

public:
    ErrorViewer();
    ~ErrorViewer();

    void Initialize();
    void Finalize();
    void Close();

    void Main();
    void Open(s32, u32);

    bool IsNoOperate();
    bool IsButton();
    bool IsLeftButton();
    bool IsRightButton();
    void DrawDRC();
    void DrawTV();
};
