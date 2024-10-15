#pragma once

#include <math/seadVectorFwd.h>

namespace al {

class AreaInitInfo;
class AreaObjDirectorGrid;
class AreaObjFactory;
class AreaObjGroup;
class AreaObjMtxConnecterHolder;

class AreaObjDirector {
    void* _0 = nullptr;
    AreaObjMtxConnecterHolder* mMtxConnecterHolder = nullptr;
    void* _10 = nullptr;
    void* _18 = nullptr;
    char _20[800] { 0 };
    void* _340 = nullptr;
    AreaObjDirectorGrid* mGrid = nullptr;

public:
    AreaObjDirector();

    void init(const AreaObjFactory* factory);
    void endInit();
    void update();
    void placement(const AreaInitInfo& info);
    void placement(const AreaInitInfo* info, int);
    void createAreaObjGroup(const AreaInitInfo& info);
    void createAreaObjGroupBuffer();
    void placementAreaObj(const AreaInitInfo& info);

    AreaObjGroup* getAreaObjGroup(const char* name);
    bool isExistAreaGroup(const char* name);
    u64 getInVolumeAreaObj(const char* name, const sead::Vector3f& trans);
    AreaObjMtxConnecterHolder* getMtxConnecterHolder() const;
};

class IUseAreaObj {
public:
    virtual AreaObjDirector* getAreaObjDirector() const = 0;
};

} // namespace al
