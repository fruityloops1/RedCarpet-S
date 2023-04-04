#pragma once

#include <basis/seadTypes.h>

namespace al {

class LiveActor;

class ActorParamHolder {
public:
    struct ActorParamBase { };

    struct ActorParamMove : ActorParamBase {
        float moveAccel;
        float gravity;
        float moveFriction;
        float turnSpeedDegree;
    };

    struct ActorParamJump : ActorParamBase {
        float speedFront;
        float speedUp;
    };

    struct ActorParamSight : ActorParamBase {
        float distance;
        float degreeH;
        float degreeV;
    };

    struct ActorParamRebound : ActorParamBase {
        float reboundRate;
        float speedMinToRebound;
        float frictionH;
    };

private:
    enum class ActorParamType : int {
        ParamS32,
        ParamF32,
        ParamMove,
        ParamJump,
        ParamSight,
        ParamRebound
    };

    struct Entry {
        const char* paramName;
        ActorParamType type;
        union {
            s32 intValue;
            f32 floatValue;
        };
        ActorParamBase* value;
    };

    int mEntryAmount = 0;
    int unk;
    Entry* mEntries = nullptr;

public:
    ActorParamHolder(LiveActor* actor);

    ActorParamMove* findParamMove(const char* name) const;
};

} // namespace al