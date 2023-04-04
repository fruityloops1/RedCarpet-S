#pragma once

namespace al {

class SensorMsg;

bool isMsgPlayerFloorTouch(const SensorMsg*);
bool isMsgTouchAssist(const SensorMsg*);

} // namespace al
