#include "Game.h"

Game::Game() :
        map("resources/maps/dev.txt")
{

}

void Game::render()
{
    map.render(graphics->getSpriteBatch());
}

void Game::update(float delta)
{
    graphics->getCamera().position += 100 * delta;
}
