#ifndef DARKNESS_SPRITE_H
#define DARKNESS_SPRITE_H


#include <memory>
#include <glm/glm.hpp>

#include "Texture.h"
#include "Graphics.h"

/**
 * Entity with a texture and model.
 */
class Sprite
{
private:
    std::unique_ptr<Texture> texture;

    std::string path;

    glm::vec2 position;
    glm::vec2 size;

public:
    Sprite(std::string path, float x, float y, int width = 0, int height = 0);

    void load();

    void render(Graphics *graphics);

    Sprite(const Sprite &other);
};


#endif //DARKNESS_SPRITE_H
