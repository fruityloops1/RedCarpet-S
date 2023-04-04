#pragma once

namespace al {

class SceneCreator;

class IUseSceneCreator {
public:
    virtual ~IUseSceneCreator() { }
    virtual SceneCreator* getSceneCreator() const = 0;
    virtual void setSceneCreator(SceneCreator* pCreator) = 0;
};

} // namespace al
