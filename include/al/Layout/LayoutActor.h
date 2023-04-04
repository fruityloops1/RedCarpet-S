#pragma once

#include "al/Camera/CameraDirector.h"
#include "al/Effect/EffectKeeper.h"
#include "al/Layout/LayoutActionKeeper.h"
#include "al/Layout/LayoutKeeper.h"
#include "al/Message/MessageSystem.h"
#include "al/Nerve/NerveKeeper.h"
#include "al/Scene/SceneObjHolder.h"

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

void startAction(al::IUseLayoutAction* pUser, const char* pActionName, const char* = nullptr);
bool isActionEnd(const al::IUseLayoutAction* pUser, const char* pActionName = nullptr);

void setPaneString(IUseLayout* pUser, const char* pPaneName, const char16_t* pText, u16 = 0, int = 0);

} // namespace al
