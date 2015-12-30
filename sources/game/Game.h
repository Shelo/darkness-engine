#ifndef DARKNESS_GAME_H
#define DARKNESS_GAME_H


#include "Application.h"
#include "TileMap.h"

class Game : public Context
{
private:
    TileMap map;

public:
    Game();

    void render();
    void update(float delta);
};


#endif //DARKNESS_GAME_H
