#pragma once

namespace al {

class MessageSystem;

class IUseMessageSystem {
public:
    virtual MessageSystem* getMessageSystem() const = 0;
};

} // namespace al
