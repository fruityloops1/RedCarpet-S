#pragma once

namespace al {

class ExecuteDirector;

class IUseExecutor {
public:
    virtual void execute() { }
    virtual void draw() { }
};

} // namespace al
