#ifndef DARKNESS_SPRITEBATCH_H
#define DARKNESS_SPRITEBATCH_H

#include <vector>
#include <OpenGL/OpenGL.h>

#include "Macros.h"

#define COMPONENTS_PER_VERTEX   8
#define MAX_SPRITES             100
#define MAX_VERTICES            MAX_SPRITES * 4
#define VERTEX_BUFFER_SIZE      COMPONENTS_PER_VERTEX * MAX_VERTICES
#define INDEX_BUFFER_SIZE       MAX_SPRITES * 6

class SpriteBatch
{
private:
    std::vector<float> vertices;
    std::vector<float> indices;

    /**
     * Vertex array object.
     */
    GLuint vao;

    /**
     * Index buffer object.
     */
    GLuint ibo;

    /**
     * Vertex buffer object.
     */
    GLuint vbo;

public:
    SpriteBatch();
};


#endif //DARKNESS_SPRITEBATCH_H
