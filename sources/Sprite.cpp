#include "Sprite.h"

Sprite::Sprite(std::string path, float x, float y, int width, int height) :
        path(path),
        position(x, y),
        size(width, height)
{

}

void Sprite::load()
{
    texture.reset(new Texture(path));

    if (size.x == 0 && size.y == 0) {
        size.x = texture->getWidth();
        size.y = texture->getHeight();
    }

    path.clear();
}

void Sprite::render(Graphics *graphics)
{
    graphics->getSpriteBatch().draw(*texture, (int) size.x, (int) size.y,
            position.x, position.y, 1, 1, 1, 1);
}

Sprite::Sprite(const Sprite &other)
{
    path = other.path;
    position = other.position;
    size = other.size;
}
