#ifndef DARKNESS_TEXTURE_H
#define DARKNESS_TEXTURE_H

#include "Macros.h"
#include "OpenGL/gl3.h"

class Texture
{
private:
    GLuint texture;
    int height;
    int width;

public:
    Texture(std::string path);

    void bind();

    int getWidth() const;
    int getHeight() const;
};


#endif //DARKNESS_TEXTURE_H
