#pragma once

#include <math/seadVectorFwd.h>

namespace al {

bool isPadTrigger(int pControllerPort, int pInputMask);

bool isPadTriggerA(int pControllerPort = -1);
bool isPadTriggerB(int pControllerPort = -1);
bool isPadTriggerX(int pControllerPort = -1);
bool isPadTriggerY(int pControllerPort = -1);
bool isPadTriggerZL(int pControllerPort = -1);
bool isPadTriggerZR(int pControllerPort = -1);
bool isPadTriggerL(int pControllerPort = -1);
bool isPadTriggerR(int pControllerPort = -1);
bool isPadTrigger1(int pControllerPort = -1);
bool isPadTrigger2(int pControllerPort = -1);
bool isPadTriggerUp(int pControllerPort = -1);
bool isPadTriggerDown(int pControllerPort = -1);
bool isPadTriggerLeft(int pControllerPort = -1);
bool isPadTriggerRight(int pControllerPort = -1);
bool isPadTriggerLeftUp(int pControllerPort = -1);
bool isPadTriggerLeftDown(int pControllerPort = -1);
bool isPadTriggerRightUp(int pControllerPort = -1);
bool isPadTriggerRightDown(int pControllerPort = -1);
bool isPadTriggerHome(int pControllerPort = -1);
bool isPadTriggerStart(int pControllerPort = -1);
bool isPadTriggerSelect(int pControllerPort = -1);
bool isPadTriggerPlus(int pControllerPort = -1);
bool isPadTriggerMinus(int pControllerPort = -1);
bool isPadTriggerTouch(int pControllerPort = -1);
bool isPadTriggerUpLeftStick(int pControllerPort = -1);
bool isPadTriggerDownLeftStick(int pControllerPort = -1);
bool isPadTriggerLeftLeftStick(int pControllerPort = -1);
bool isPadTriggerRightLeftStick(int pControllerPort = -1);
bool isPadTriggerUpRightStick(int pControllerPort = -1);
bool isPadTriggerDownRightStick(int pControllerPort = -1);
bool isPadTriggerLeftRightStick(int pControllerPort = -1);
bool isPadTriggerRightRightStick(int pControllerPort = -1);
bool isPadTriggerAnyABXY(int pControllerPort = -1);
bool isPadTriggerAny(int pControllerPort = -1);
bool isPadTriggerLeftStick(int pControllerPort = -1);
bool isPadTriggerRightStick(int pControllerPort = -1);
bool isPadTriggerPressLeftStick(int pControllerPort = -1);
bool isPadTriggerPressRightStick(int pControllerPort = -1);

void setPadRepeat(int, int, int, int);

bool isPadRepeatA(int pControllerPort = -1);
bool isPadRepeatB(int pControllerPort = -1);
bool isPadRepeatX(int pControllerPort = -1);
bool isPadRepeatY(int pControllerPort = -1);
bool isPadRepeatZL(int pControllerPort = -1);
bool isPadRepeatZR(int pControllerPort = -1);
bool isPadRepeatL(int pControllerPort = -1);
bool isPadRepeatR(int pControllerPort = -1);
bool isPadRepeat1(int pControllerPort = -1);
bool isPadRepeat2(int pControllerPort = -1);
bool isPadRepeatUp(int pControllerPort = -1);
bool isPadRepeatDown(int pControllerPort = -1);
bool isPadRepeatLeft(int pControllerPort = -1);
bool isPadRepeatRight(int pControllerPort = -1);
bool isPadRepeatHome(int pControllerPort = -1);
bool isPadRepeatStart(int pControllerPort = -1);
bool isPadRepeatSelect(int pControllerPort = -1);
bool isPadRepeatPlus(int pControllerPort = -1);
bool isPadRepeatMinus(int pControllerPort = -1);
bool isPadRepeatTouch(int pControllerPort = -1);
bool isPadRepeatUpLeftStick(int pControllerPort = -1);
bool isPadRepeatDownLeftStick(int pControllerPort = -1);
bool isPadRepeatLeftLeftStick(int pControllerPort = -1);
bool isPadRepeatRightLeftStick(int pControllerPort = -1);
bool isPadRepeatUpRightStick(int pControllerPort = -1);
bool isPadRepeatDownRightStick(int pControllerPort = -1);
bool isPadRepeatLeftRightStick(int pControllerPort = -1);
bool isPadRepeatRightRightStick(int pControllerPort = -1);

bool isPadHold(int pControllerPort, int pInputMask);

bool isPadHoldA(int pControllerPort = -1);
bool isPadHoldB(int pControllerPort = -1);
bool isPadHoldX(int pControllerPort = -1);
bool isPadHoldY(int pControllerPort = -1);
bool isPadHoldZL(int pControllerPort = -1);
bool isPadHoldZR(int pControllerPort = -1);
bool isPadHoldL(int pControllerPort = -1);
bool isPadHoldR(int pControllerPort = -1);
bool isPadHold1(int pControllerPort = -1);
bool isPadHold2(int pControllerPort = -1);
bool isPadHoldUp(int pControllerPort = -1);
bool isPadHoldDown(int pControllerPort = -1);
bool isPadHoldLeft(int pControllerPort = -1);
bool isPadHoldRight(int pControllerPort = -1);
bool isPadHoldLeftUp(int pControllerPort = -1);
bool isPadHoldLeftDown(int pControllerPort = -1);
bool isPadHoldRightUp(int pControllerPort = -1);
bool isPadHoldRightDown(int pControllerPort = -1);
bool isPadHoldHome(int pControllerPort = -1);
bool isPadHoldStart(int pControllerPort = -1);
bool isPadHoldSelect(int pControllerPort = -1);
bool isPadHoldPlus(int pControllerPort = -1);
bool isPadHoldMinus(int pControllerPort = -1);
bool isPadHoldAny(int pControllerPort = -1);
bool isPadHoldAnyWithoutStick(int pControllerPort = -1);
bool isPadHoldTouch(int pControllerPort = -1);
bool isPadHoldUpLeftStick(int pControllerPort = -1);
bool isPadHoldDownLeftStick(int pControllerPort = -1);
bool isPadHoldLeftLeftStick(int pControllerPort = -1);
bool isPadHoldRightLeftStick(int pControllerPort = -1);
bool isPadHoldUpRightStick(int pControllerPort = -1);
bool isPadHoldDownRightStick(int pControllerPort = -1);
bool isPadHoldLeftRightStick(int pControllerPort = -1);
bool isPadHoldRightRightStick(int pControllerPort = -1);
bool isPadHoldLeftStick(int pControllerPort = -1);
bool isPadHoldRightStick(int pControllerPort = -1);
bool isPadHoldAnyABXY(int pControllerPort = -1);

bool isPadReleaseA(int pControllerPort = -1);
bool isPadReleaseB(int pControllerPort = -1);
bool isPadReleaseX(int pControllerPort = -1);
bool isPadReleaseY(int pControllerPort = -1);
bool isPadReleaseZL(int pControllerPort = -1);
bool isPadReleaseZR(int pControllerPort = -1);
bool isPadReleaseL(int pControllerPort = -1);
bool isPadReleaseR(int pControllerPort = -1);
bool isPadRelease1(int pControllerPort = -1);
bool isPadRelease2(int pControllerPort = -1);
bool isPadReleaseUp(int pControllerPort = -1);
bool isPadReleaseDown(int pControllerPort = -1);
bool isPadReleaseLeft(int pControllerPort = -1);
bool isPadReleaseRight(int pControllerPort = -1);
bool isPadReleaseLeftUp(int pControllerPort = -1);
bool isPadReleaseLeftDown(int pControllerPort = -1);
bool isPadReleaseRightUp(int pControllerPort = -1);
bool isPadReleaseRightDown(int pControllerPort = -1);
bool isPadReleaseHome(int pControllerPort = -1);
bool isPadReleaseStart(int pControllerPort = -1);
bool isPadReleaseSelect(int pControllerPort = -1);
bool isPadReleasePlus(int pControllerPort = -1);
bool isPadReleaseMinus(int pControllerPort = -1);
bool isPadReleaseTouch(int pControllerPort = -1);
bool isPadReleaseUpLeftStick(int pControllerPort = -1);
bool isPadReleaseDownLeftStick(int pControllerPort = -1);
bool isPadReleaseLeftLeftStick(int pControllerPort = -1);
bool isPadReleaseRightLeftStick(int pControllerPort = -1);
bool isPadReleaseUpRightStick(int pControllerPort = -1);
bool isPadReleaseDownRightStick(int pControllerPort = -1);
bool isPadReleaseLeftRightStick(int pControllerPort = -1);
bool isPadReleaseRightRightStick(int pControllerPort = -1);

const sead::Vector2f& getLeftStick(int pControllerPort = -1);
const sead::Vector2f& getRightStick(int pControllerPort = -1);

} // namespace al
