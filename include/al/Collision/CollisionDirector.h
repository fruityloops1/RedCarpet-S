#pragma once

#include "al/Base/Types.h"
#include "al/Execute/ExecuteDirector.h"
#include <container/seadPtrArray.h>
#include <math/seadVectorFwd.h>
#include <prim/seadDelegate.h>

namespace al {

class CollisionParts;
class CollisionPartsFilterBase;
class CollisionPartsKeeperPtrArray;
class DiskHitInfo;
class ExecuteDirector;
class SphereHitInfo;
class TriangleFilterBase;

class CollisionDirector : public IUseExecutor {
    void* _8 = nullptr;
    void* mCollisionPartsKeeper = nullptr;
    CollisionPartsKeeperPtrArray* _18 = nullptr;
    const CollisionPartsFilterBase* _20 = nullptr;
    const TriangleFilterBase* _28 = nullptr;
    void* _30 = nullptr;
    void* _38 = nullptr;
    void* _40 = nullptr;
    void* _48 = nullptr;
    void* _50 = nullptr;

public:
    CollisionDirector(ExecuteDirector*, s32);

    void endInit();
    void setPartsFilter(const CollisionPartsFilterBase*);
    void setTriFilter(const TriangleFilterBase*);
    void checkStrikeSphere(const sead::Vector3f&, float, bool, const sead::Vector3f&);
    void checkStrikeArrow(const sead::Vector3f&, const sead::Vector3f&);
    void checkStrikeSphereForPlayer(const sead::Vector3f&, float);
    void* getStrikeArrowInfo(s32 idx);
    s32 getStrikeArrowInfoNum();
    void* getStrikeSphereInfo(s32 idx);
    void* getSphereHitInfoArrayForCollider(SphereHitInfo**, u32*);
    void execute() override;
    void searchCollisionPartsWithSphere();
    void validateCollisionPartsPtrArray(sead::PtrArray<CollisionParts>*);
    void invalidateCollisionPartsPtrArray();
    sead::PtrArray<CollisionParts>* getCollisionPartsPtrArray() const;
    void searchCollisionPartsWithSphere(const sead::Vector3f&, float, sead::IDelegate1<CollisionParts*>&, const CollisionPartsFilterBase*);
};

class IUseCollision {
public:
    virtual CollisionDirector* getCollisionDirector() const = 0;
};

} // namespace al
