#pragma once

#include "al/Camera/CameraDirector_RS.h"
#include "al/Camera/CameraPoser_RS.h"
#include "al/Placement/PlacementInfo.h"

namespace alCameraFunction {

void initCamera(al::CameraPoser_RS* pCamera, const al::IUseCamera_RS* pUser, const al::PlacementInfo& pInfo, const char*, int);

} // namespace alCameraFunction
