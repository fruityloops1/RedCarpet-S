#pragma once

#include "Game/Player/PlayerModel.h"
#include <container/seadPtrArray.h>

class PlayerModelHolder {
    u8 inherit[0x18];
    sead::PtrArray<PlayerModel> mModels;
    int mCurModelIndex = 0;
    u8 _34[0x28];
    int mBufferSize = 0;
    u8 _60;

public:
    PlayerModelHolder(int pAllocBufferSize);

    virtual void change(int pIdx);
    virtual void show();
    virtual void hide();
    virtual bool isHidden() const;
    virtual void showSilhouette();
    virtual void hideSilhouette();
    virtual bool isSilhouetteHidden() const;
    virtual void showShadow();
    virtual void hideShadow();
    virtual bool isShadowHidden() const;
    virtual void validateMash();
    virtual void invalidateMash();
    virtual bool isMash() const;

    void validateTailDynamics();

    void registerModel(int pIdx, PlayerModel* pModel);
    void initCurrentModel(int pIdx);
};