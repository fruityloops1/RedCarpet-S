#pragma once

namespace al {

class LiveActor;

class PlayerHolder {
    struct Player;
    Player* mPlayers = nullptr;
    int mBufferSize = 0;

public:
    int mPlayerNum = 0;

    PlayerHolder(int bufferSize);
    LiveActor* tryGetPlayer(int index);
};

int getPlayerNumMax(const LiveActor* pActor);
LiveActor* getPlayerActor(const LiveActor* pActor, int pIdx);

} // namespace al
