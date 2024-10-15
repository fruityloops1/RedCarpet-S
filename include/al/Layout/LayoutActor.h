#pragma once

#include "al/Camera/CameraDirector.h"
#include "al/Effect/EffectKeeper.h"
#include "al/Layout/LayoutActionKeeper.h"
#include "al/Layout/LayoutKeeper.h"
#include "al/Message/MessageSystem.h"
#include "al/Nerve/NerveKeeper.h"
#include "al/Scene/SceneObjHolder.h"
#include <sead/prim/seadSafeString.h>

namespace al {

class LayoutPartsActorKeeper;
class LayoutSceneInfo;
class LayoutInitInfo;

class LayoutActor : public IUseNerve,
                    public IUseLayout,
                    public IUseLayoutAction,
                    public IUseMessageSystem,
                    public IUseCamera,
                    public IUseAudioKeeper,
                    public IUseEffectKeeper,
                    public IUseSceneObjHolder {
    sead::FixedSafeString<0x80> mName;
    NerveKeeper* mNerveKeeper = nullptr;
    LayoutActionKeeper* mActionKeeper = nullptr;
    class TextPaneAnimator* mTextPaneAnimator = nullptr;
    EffectKeeper* mEffectKeeper = nullptr;
    AudioKeeper* mAudioKeeper = nullptr;
    class LayoutExecuteInfo* mExecuteInfo = nullptr;
    LayoutSceneInfo* mSceneInfo = nullptr;
    LayoutPartsActorKeeper* mPartsActorKeeper = nullptr;
    bool mIsAlive = false;

public:
    LayoutActor(const char* name);

    NerveKeeper* getNerveKeeper() const override;
    virtual void appear();
    virtual void kill();
    virtual void movement();
    virtual void calcAnim(bool);
    const char* getName() const override;
    EffectKeeper* getEffectKeeper() const override;
    AudioKeeper* getAudioKeeper() const override;
    LayoutActionKeeper* getLayoutActionKeeper() const override;
    LayoutKeeper* getLayoutKeeper() const override;
    SceneCameraInfo* getSceneCameraInfo() const override;
    SceneObjHolder* getSceneObjHolder() const override;
    MessageSystem* getMessageSystem() const override;
    virtual void control();

    void initActionKeeper();
    void initAudioKeeper(AudioKeeper*);
    void initLayoutKeeper(LayoutKeeper*);
    void initLayoutPartsActorKeeper(int);
    void initNerve(const Nerve*, int step = 0);
    void initSceneInfo(LayoutSceneInfo*);
};

void startAction(al::IUseLayoutAction* user, const char* actionName, const char* = nullptr);
bool isActionEnd(const al::IUseLayoutAction* user, const char* actionName = nullptr);

void setPaneString(IUseLayout* user, const char* paneName, const char16_t* text, u16 = 0, int = 0);

} // namespace al
