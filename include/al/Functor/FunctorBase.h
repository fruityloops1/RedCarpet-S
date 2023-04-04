#pragma once

namespace al {

class FunctorBase {
public:
    virtual void operator()() const { }
    virtual FunctorBase* clone() const { return nullptr; }
};

} // namespace al
