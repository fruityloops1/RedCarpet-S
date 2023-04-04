#pragma once

namespace al {

class LiveActor;

class SceneStopCtrl {
    int _0;
    int _4;
    bool _8;
    bool _9;

public:
    SceneStopCtrl();

    // haha ↓↓
    void reqeustStopScene(int, int, bool, bool);
    void update();
};

void stopScene(LiveActor*, int, int, bool, bool);

} // namespace al
