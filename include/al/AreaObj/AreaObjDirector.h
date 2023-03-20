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

    void init(const AreaObjFactory* pFactory);
    void endInit();
    void update();
    void placement(const AreaInitInfo& pInfo);
    void placement(const AreaInitInfo* pInfo, int);
    void createAreaObjGroup(const AreaInitInfo& pInfo);
    void createAreaObjGroupBuffer();
    void placementAreaObj(const AreaInitInfo& pInfo);

    AreaObjGroup* getAreaObjGroup(const char* pName);
    bool isExistAreaGroup(const char* pName);
    u64 getInVolumeAreaObj(const char* pName, const sead::Vector3f& pTrans);
    AreaObjMtxConnecterHolder* getMtxConnecterHolder() const;
};

class IUseAreaObj {
public:
    virtual AreaObjDirector* getAreaObjDirector() const = 0;
};

} // namespace al
