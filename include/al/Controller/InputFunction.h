#pragma once

#include <math/seadVectorFwd.h>

namespace al {

bool isPadTrigger(int port, int inputMask);

bool isPadTriggerA(int port = -1);
bool isPadTriggerB(int port = -1);
bool isPadTriggerX(int port = -1);
bool isPadTriggerY(int port = -1);
bool isPadTriggerZL(int port = -1);
bool isPadTriggerZR(int port = -1);
bool isPadTriggerL(int port = -1);
bool isPadTriggerR(int port = -1);
bool isPadTrigger1(int port = -1);
bool isPadTrigger2(int port = -1);
bool isPadTriggerUp(int port = -1);
bool isPadTriggerDown(int port = -1);
bool isPadTriggerLeft(int port = -1);
bool isPadTriggerRight(int port = -1);
bool isPadTriggerLeftUp(int port = -1);
bool isPadTriggerLeftDown(int port = -1);
bool isPadTriggerRightUp(int port = -1);
bool isPadTriggerRightDown(int port = -1);
bool isPadTriggerHome(int port = -1);
bool isPadTriggerStart(int port = -1);
bool isPadTriggerSelect(int port = -1);
bool isPadTriggerPlus(int port = -1);
bool isPadTriggerMinus(int port = -1);
bool isPadTriggerTouch(int port = -1);
bool isPadTriggerUpLeftStick(int port = -1);
bool isPadTriggerDownLeftStick(int port = -1);
bool isPadTriggerLeftLeftStick(int port = -1);
bool isPadTriggerRightLeftStick(int port = -1);
bool isPadTriggerUpRightStick(int port = -1);
bool isPadTriggerDownRightStick(int port = -1);
bool isPadTriggerLeftRightStick(int port = -1);
bool isPadTriggerRightRightStick(int port = -1);
bool isPadTriggerAnyABXY(int port = -1);
bool isPadTriggerAny(int port = -1);
bool isPadTriggerLeftStick(int port = -1);
bool isPadTriggerRightStick(int port = -1);
bool isPadTriggerPressLeftStick(int port = -1);
bool isPadTriggerPressRightStick(int port = -1);

void setPadRepeat(int, int, int, int);

bool isPadRepeatA(int port = -1);
bool isPadRepeatB(int port = -1);
bool isPadRepeatX(int port = -1);
bool isPadRepeatY(int port = -1);
bool isPadRepeatZL(int port = -1);
bool isPadRepeatZR(int port = -1);
bool isPadRepeatL(int port = -1);
bool isPadRepeatR(int port = -1);
bool isPadRepeat1(int port = -1);
bool isPadRepeat2(int port = -1);
bool isPadRepeatUp(int port = -1);
bool isPadRepeatDown(int port = -1);
bool isPadRepeatLeft(int port = -1);
bool isPadRepeatRight(int port = -1);
bool isPadRepeatHome(int port = -1);
bool isPadRepeatStart(int port = -1);
bool isPadRepeatSelect(int port = -1);
bool isPadRepeatPlus(int port = -1);
bool isPadRepeatMinus(int port = -1);
bool isPadRepeatTouch(int port = -1);
bool isPadRepeatUpLeftStick(int port = -1);
bool isPadRepeatDownLeftStick(int port = -1);
bool isPadRepeatLeftLeftStick(int port = -1);
bool isPadRepeatRightLeftStick(int port = -1);
bool isPadRepeatUpRightStick(int port = -1);
bool isPadRepeatDownRightStick(int port = -1);
bool isPadRepeatLeftRightStick(int port = -1);
bool isPadRepeatRightRightStick(int port = -1);

bool isPadHold(int port, int pInputMask);

bool isPadHoldA(int port = -1);
bool isPadHoldB(int port = -1);
bool isPadHoldX(int port = -1);
bool isPadHoldY(int port = -1);
bool isPadHoldZL(int port = -1);
bool isPadHoldZR(int port = -1);
bool isPadHoldL(int port = -1);
bool isPadHoldR(int port = -1);
bool isPadHold1(int port = -1);
bool isPadHold2(int port = -1);
bool isPadHoldUp(int port = -1);
bool isPadHoldDown(int port = -1);
bool isPadHoldLeft(int port = -1);
bool isPadHoldRight(int port = -1);
bool isPadHoldLeftUp(int port = -1);
bool isPadHoldLeftDown(int port = -1);
bool isPadHoldRightUp(int port = -1);
bool isPadHoldRightDown(int port = -1);
bool isPadHoldHome(int port = -1);
bool isPadHoldStart(int port = -1);
bool isPadHoldSelect(int port = -1);
bool isPadHoldPlus(int port = -1);
bool isPadHoldMinus(int port = -1);
bool isPadHoldAny(int port = -1);
bool isPadHoldAnyWithoutStick(int port = -1);
bool isPadHoldTouch(int port = -1);
bool isPadHoldUpLeftStick(int port = -1);
bool isPadHoldDownLeftStick(int port = -1);
bool isPadHoldLeftLeftStick(int port = -1);
bool isPadHoldRightLeftStick(int port = -1);
bool isPadHoldUpRightStick(int port = -1);
bool isPadHoldDownRightStick(int port = -1);
bool isPadHoldLeftRightStick(int port = -1);
bool isPadHoldRightRightStick(int port = -1);
bool isPadHoldLeftStick(int port = -1);
bool isPadHoldRightStick(int port = -1);
bool isPadHoldAnyABXY(int port = -1);

bool isPadReleaseA(int port = -1);
bool isPadReleaseB(int port = -1);
bool isPadReleaseX(int port = -1);
bool isPadReleaseY(int port = -1);
bool isPadReleaseZL(int port = -1);
bool isPadReleaseZR(int port = -1);
bool isPadReleaseL(int port = -1);
bool isPadReleaseR(int port = -1);
bool isPadRelease1(int port = -1);
bool isPadRelease2(int port = -1);
bool isPadReleaseUp(int port = -1);
bool isPadReleaseDown(int port = -1);
bool isPadReleaseLeft(int port = -1);
bool isPadReleaseRight(int port = -1);
bool isPadReleaseLeftUp(int port = -1);
bool isPadReleaseLeftDown(int port = -1);
bool isPadReleaseRightUp(int port = -1);
bool isPadReleaseRightDown(int port = -1);
bool isPadReleaseHome(int port = -1);
bool isPadReleaseStart(int port = -1);
bool isPadReleaseSelect(int port = -1);
bool isPadReleasePlus(int port = -1);
bool isPadReleaseMinus(int port = -1);
bool isPadReleaseTouch(int port = -1);
bool isPadReleaseUpLeftStick(int port = -1);
bool isPadReleaseDownLeftStick(int port = -1);
bool isPadReleaseLeftLeftStick(int port = -1);
bool isPadReleaseRightLeftStick(int port = -1);
bool isPadReleaseUpRightStick(int port = -1);
bool isPadReleaseDownRightStick(int port = -1);
bool isPadReleaseLeftRightStick(int port = -1);
bool isPadReleaseRightRightStick(int port = -1);

const sead::Vector2f& getLeftStick(int port = -1);
const sead::Vector2f& getRightStick(int port = -1);

} // namespace al
