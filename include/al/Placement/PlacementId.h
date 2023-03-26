#pragma once

namespace al {

class PlacementInfo;

class PlacementId {
    const char* mPlacementId = nullptr;
    const char* mLayerConfigName = nullptr;
    const char* mUnitConfigName = nullptr;
    const char* mUnitConfigId = nullptr;
    const char* mCommonId = nullptr;

public:
    PlacementId();
    PlacementId(const char* pPlacementId, const char* pLayerConfigName, const char* pUnitConfigName, const char* pUnitConfigId);

    void init(const PlacementInfo& pInfo);
    bool isEqual(const PlacementId& rhs) const;
};

} // namespace al
