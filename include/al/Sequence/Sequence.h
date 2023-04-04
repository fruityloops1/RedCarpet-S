#pragma once

#include "al/Audio/AudioKeeper.h"
#include "al/Nerve/NerveExecutor.h"
#include "al/Sequence/SceneCreator.h"
#include "nerd/ErrorViewer.h"
#include <prim/seadSafeString.h>

namespace al {

class Scene;
class SequenceInitInfo;

class Sequence : public NerveExecutor, public IUseAudioKeeper, public IUseSceneCreator {
    sead::FixedSafeString<64> mName;
    al::Scene* mCurrentScene = nullptr;
    al::Scene* mCurrentInitScene = nullptr;
    SceneCreator* mSceneCreator = nullptr;
    AudioDirector* mAudioDirector = nullptr;
    AudioKeeper* mAudioKeeper = nullptr;
    void* _A0 = nullptr;
    bool mIsAlive = true;

public:
    ~Sequence() override;
    virtual void init(const SequenceInitInfo& pInfo);
    virtual void update();
    virtual void kill();
    virtual void drawMain();
    virtual void drawSub();
    AudioKeeper* getAudioKeeper() const override;
    virtual bool isDisposable() const;
    virtual Scene* getCurrentScene() const;
    ErrorViewer* getErrorViewer() const;
    SceneCreator* getSceneCreator() const override;
    void setSceneCreator(SceneCreator*) override;
    AudioDirector* getAudioDirector() const { return mAudioDirector; }
};

} // namespace al
