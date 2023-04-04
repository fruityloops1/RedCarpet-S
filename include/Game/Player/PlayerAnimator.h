#pragma once

#include "Game/Player/IUsePlayerRetargettingSelector.h"
#include "Game/Player/PlayerModelHolder.h"
#include <prim/seadSafeString.h>

class IUsePlayerRetargettingSelector;

class PlayerAnimator {
    al::LiveActor* mParent = nullptr;
    PlayerModelHolder* mModelHolder = nullptr;
    IUsePlayerRetargettingSelector* mRetargettingSelector = nullptr;
    class PlayerAnimFrameCtrl* mAnimFrameCtrl = nullptr;
    bool mIsSubAnim;
    u8 _29[0x7];
    float mBlendWeights[6];
    u8 _48[0x10];
    sead::BufferedSafeString mCurAnimName;
    u8 _70[0x40];
    sead::BufferedSafeString mCurSubAnimName;
    u8 _C8[0xa0];

    PlayerAnimator(al::LiveActor* pHost, PlayerModelHolder* pModelHolder, IUsePlayerRetargettingSelector* pRetargettingSelector);

public:
    void init();
    void update();

    virtual ~PlayerAnimator();
    virtual void vunk1();
    virtual void startAnim(const sead::SafeString& pAnimName);
    virtual void setAnimRate(float pRate);
    virtual void setAnimRateCommon(float pRate);
    virtual void setAnimFrame(float pFrame);
    virtual bool isAnimEnd() const;
    virtual bool isAnim(const sead::SafeString& pAnimName) const;
    virtual bool isAnimReverse() const;
    virtual float getAnimFrame() const;
    virtual float getAnimFrameMax() const;
    virtual void clearInterpolation();
    virtual const char* getAnimName() const;
    virtual void startSubAnim(const sead::SafeString& pSubAnimName);
    virtual void endSubAnim();
    virtual bool isSubAnimBinding() const;
    virtual bool isSubAnimEnd() const;
    virtual bool isSubAnim(const sead::SafeString& pSubAnimName) const;
    virtual bool isSubAnimReverse() const;
    virtual float getSubAnimFrame() const;
    virtual float getAnimFrameMax(const sead::SafeString& pAnimName) const;
    virtual void startMaterialAnim(const sead::SafeString& pMclAnimName);
    virtual bool isMaterialAnimEnd() const;
    virtual void setWeightSixfold(float, float, float, float, float, float);
    virtual float getWeight(int index) const;
    virtual void vunk2();
};