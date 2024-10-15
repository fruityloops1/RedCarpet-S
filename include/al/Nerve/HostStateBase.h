#pragma once

#include "al/Nerve/NerveStateBase.h"

namespace al {

template <typename T>
class HostStateBase : public NerveStateBase {
protected:
    T* const mHost = nullptr;

public:
    HostStateBase(const char* name, T* host)
        : NerveStateBase(name)
        , mHost(host)
    {
    }
};

} // namespace al
