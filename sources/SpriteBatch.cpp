#include <OpenGL/gl3.h>
#include "SpriteBatch.h"

SpriteBatch::SpriteBatch() :
        vertices(VERTEX_BUFFER_SIZE),
        indices(INDEX_BUFFER_SIZE)
{
    glGenVertexArrays(1, &vao);

    glGenBuffers(1, &ibo);
    glGenBuffers(1, &vbo);
}
