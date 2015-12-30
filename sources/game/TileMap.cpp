#include <SpriteBatch.h>
#include "TileMap.h"

TileMap::TileMap(std::string path) :
        wall("resources/moka.png"),
        floor("resources/moka.png")
{
    std::ifstream map(path);

    char type;
    int x;
    int y;

    while (map >> type >> x >> y) {
        tiles[x][y] = type == 'w' ? TileType::WALL : TileType::FLOOR;
    }
}

void TileMap::render(SpriteBatch &batch)
{
    for (int x = 0; x < 512; ++x) {
        for (int y = 0; y < 512; ++y) {
            if (tiles[x][y] != TileType::NONE) {
                batch.draw(floor, 10, 10, x * 10, y * 10, 1, 1, 1, 1);
            }
        }
    }
}
