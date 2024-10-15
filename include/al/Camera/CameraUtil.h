#pragma once

#include "al/Camera/CameraDirector_RS.h"
#include "al/Camera/CameraPoser_RS.h"
#include "al/Placement/PlacementInfo.h"

namespace alCameraFunction {

void initCamera(al::CameraPoser_RS* camera, const al::IUseCamera_RS* user, const al::PlacementInfo& info, const char*, int);

} // namespace alCameraFunction
