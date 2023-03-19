#pragma once

namespace al {

class NerveKeeper;
class Nerve {
public:
    virtual void execute(NerveKeeper* pParent) const = 0;
    virtual void executeOnEnd(NerveKeeper* pParent) const { }
};

#define NERVE_DEF(CLASS, ACTION)                                    \
    struct CLASS##Nrv##ACTION : public ::al::Nerve {                \
        virtual void execute(::al::NerveKeeper* pParent) const      \
        {                                                           \
            static_cast<CLASS*>(pParent->getHost())->exe##ACTION(); \
        }                                                           \
    };                                                              \
    const CLASS##Nrv##ACTION nrv##CLASS##ACTION = CLASS##Nrv##ACTION();

#define NERVE_DEF_END(CLASS, ACTION, ENDACTION)                        \
    struct CLASS##Nrv##ACTION : public ::al::Nerve {                   \
        virtual void execute(::al::NerveKeeper* pParent) const         \
        {                                                              \
            static_cast<CLASS*>(pParent->getHost())->exe##ACTION();    \
        }                                                              \
        virtual void executeOnEnd(::al::NerveKeeper* pParent) const    \
        {                                                              \
            static_cast<CLASS*>(pParent->getHost())->exe##ENDACTION(); \
        }                                                              \
    };                                                                 \
    const CLASS##Nrv##ACTION nrv##CLASS##ACTION = CLASS##Nrv##ACTION();

} // namespace al
