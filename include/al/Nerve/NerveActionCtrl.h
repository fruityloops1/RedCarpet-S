#pragma once

#include "al/Nerve/Nerve.h"

namespace alNerveFunction {
class NerveActionCollector;
} // namespace alNerveFunction

namespace al {

class NerveActionCtrl;
class NerveAction : public Nerve {
    NerveAction* mNextNode;

public:
    NerveAction();
    virtual const char* getName() const = 0;

    friend class alNerveFunction::NerveActionCollector;
    friend class NerveActionCtrl;
};
} // namespace al

namespace alNerveFunction {

class NerveActionCollector {
    int mNumNodes = 0;
    al::NerveAction* mStartNode = nullptr;
    al::NerveAction* mEndNode = nullptr;

    static NerveActionCollector* sCurrentCollector;

public:
    NerveActionCollector();

    void addNerve(al::NerveAction* nerve);

    static NerveActionCollector* getCurrentCollector() { return sCurrentCollector; }
    friend class al::NerveActionCtrl;
};

} // namespace alNerveFunction

namespace al {

class NerveActionCtrl {
    int mNumNerveActions = 0;
    NerveAction** mNerveActions = nullptr;

public:
    NerveActionCtrl(alNerveFunction::NerveActionCollector* pCollector);
    NerveAction* findNerve(const char* name) const;
};

} // namespace al

#define NERVEACTION_DEF(CLASS, ACTION)                             \
    struct CLASS##Nrv##ACTION : public ::al::NerveAction {         \
        virtual void execute(::al::NerveKeeper* keeper) const      \
        {                                                          \
            static_cast<CLASS*>(keeper->getHost())->exe##ACTION(); \
        }                                                          \
        virtual const char* getName() const                        \
        {                                                          \
            return #ACTION;                                        \
        }                                                          \
    };                                                             \
    const CLASS##Nrv##ACTION ACTION = CLASS##Nrv##ACTION();

#define NERVEACTION_DEF_END(CLASS, ACTION, ENDACTION)                 \
    struct CLASS##Nrv##ACTION : public ::al::NerveAction {            \
        virtual void execute(::al::NerveKeeper* keeper) const         \
        {                                                             \
            static_cast<CLASS*>(keeper->getHost())->exe##ACTION();    \
        }                                                             \
        virtual void executeOnEnd(::al::NerveKeeper* keeper) const    \
        {                                                             \
            static_cast<CLASS*>(keeper->getHost())->exe##ENDACTION(); \
        }                                                             \
        virtual const char* getName() const                           \
        {                                                             \
            return #ACTION;                                           \
        }                                                             \
    };                                                                \
    const CLASS##Nrv##ACTION ACTION = CLASS##Nrv##ACTION();
