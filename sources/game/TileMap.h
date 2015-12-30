#ifndef DARKNESS_TILEMAP_H
#define DARKNESS_TILEMAP_H

#include <fstream>
#include <SpriteBatch.h>

#include "Macros.h"


class TileMap
{
private:
    enum class TileType
    {
        NONE,
        FLOOR,
        WALL,
    };

    TileType tiles[512][512] = { TileType::NONE };

    Texture wall;
    Texture floor;

public:
    TileMap(std::string path);

    void render(SpriteBatch &batch);
};


#endif //DARKNESS_TILEMAP_H
