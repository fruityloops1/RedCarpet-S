#pragma once

namespace al {

class RailRider {
};

class IUseRail {
    virtual RailRider* getRailRider() const = 0;
};

} // namespace al
