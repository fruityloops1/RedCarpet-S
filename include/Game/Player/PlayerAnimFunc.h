#pragma once

enum class EPlayerFigure : int {
    None = 0,
    Mini = 1,
    Fire = 2,
    Climb = 3,
    RaccoonDog = 4,
    Boomerang = 5,
    RaccoonDogWhite = 6,
    Manekineko = 7,
    ClimbWhite = 8,
    ClimbGiga = 9
};

class PlayerAnimFunc {
public:
    static const char* getFigureString(EPlayerFigure);
};
