#pragma once

#include <math/seadMatrix.h>
#include <math/seadVectorFwd.h>

namespace al {

class AudioDirector;
class AudioSituationDirector;
class BgmKeeper;
class ModelKeeper;
class MeInfo;
class SeKeeper;

class AudioKeeper {
    AudioSituationDirector* mSituationDirector;
    void* _8;
    void* _10;
    void* _18;
    SeKeeper* mSeKeeper;
    BgmKeeper* mBgmKeeper;
    void* _30;
    void* _38;
    void* _40;
    bool _48;

public:
    AudioKeeper();

    void init(const AudioDirector* pAudioDirector, const char*, const sead::Vector3f*, const sead::Matrix34f*, const ModelKeeper* pModelKeeper);
    void initSeKeeper(const AudioDirector* pAudioDirector, const char*, const sead::Vector3f*, const sead::Matrix34f*, const ModelKeeper* pModelKeeper);
    void initBgmKeeper(const AudioDirector* pAudioDirector, const char*);
    void initOtherAudio(const AudioDirector* pAudioDirector);

    void update();
    void validate();
    void invalidate();
    void startClipped();
    void endClipped();
    void appear();
    void kill();
};

class IUseAudioKeeper {
public:
    virtual AudioKeeper* getAudioKeeper() const = 0;
};

} // namespace al
