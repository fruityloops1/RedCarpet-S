#pragma once

#include "al/Sequence/Sequence.h"

class IUseUnknownSequence {
    virtual void unknown(const char*);
};

class GameDataHolder;

class ProductSequence : public al::Sequence, IUseUnknownSequence {
    void* _B8 = nullptr;
    GameDataHolder* mGameDataHolder = nullptr;
    void* _C8[3];
    class ProductStateBoot* mStateBoot = nullptr;
    class ProductStateTitle* mStateTitle = nullptr;
    class ProductStateSingleModeOpening* mStateSingleModeOpening = nullptr;
    class ProductStateSingleMode* mStateSingleMode = nullptr;
    class ProductStateSingleModeEnding* mStateSingleModeEnding = nullptr;
    class ProductStateCourseSelect* mStateCourseSelect = nullptr;
    class ProductStateNetworkStop* mStateNetworkStop = nullptr;
    class ProductStateStage* mStateStage = nullptr;
    class ProductStateEnding* mStateEnding = nullptr;
    class ProductStateAfterEndingEvent* mStateAfterEndingEvent = nullptr;
    class ProductStateTopMenu* mStateTopMenu = nullptr;
    class ProductStateLuigiBros* mStateLuigiBros = nullptr;
    u8 _140[0x70];

public:
    ~ProductSequence() override;
    void init(const al::SequenceInitInfo& pInfo) override;
    void update() override;
    void drawMain() override;
    void drawSub() override;
    bool isDisposable() const override;
    al::Scene* getCurrentScene() const override;
    void unknown(const char*) override;

    void exeBoot();
    void exeTitle();
    void exeSingleModeOpening();
    void exeSingleMode();
    void exeSingleModeEnding();
    void exeCourseSelect();
    void exeNetworkStop();
    void exeStage();
    void exeEnding();
    void exeAfterEndingEvent();
    void exeTopMenu();
    void exeLuigiBros();
};
