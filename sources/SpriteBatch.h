#ifndef DARKNESS_SPRITEBATCH_H
#define DARKNESS_SPRITEBATCH_H

#include <vector>
#include <OpenGL/OpenGL.h>
#include <glm/detail/type_vec.hpp>

#include "Macros.h"
#include "Texture.h"

#define COMPONENTS_PER_VERTEX   8
#define MAX_SPRITES             200
#define MAX_VERTICES            MAX_SPRITES * 4
#define VERTEX_BUFFER_SIZE      COMPONENTS_PER_VERTEX * MAX_VERTICES
#define INDEX_BUFFER_SIZE       MAX_SPRITES * 6

class SpriteBatch
{
private:
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;

    /** Vertex array object. */
    GLuint vao;

    /** Index buffer object. */
    GLuint ibo;

    /** Vertex buffer object. */
    GLuint vbo;

    /** Current texture. */
    Texture *texture;

    /** Vertex buffer counter */
    size_t vbc;

    /** Index buffer counter */
    size_t ibc;

    /** Vertex counter */
    GLuint vertexCounter;

    /**
     * Set the current texture, checking if we need to flush or not.
     */
    void setTexture(Texture &texture);


public:
    SpriteBatch();

    void render();

    void draw(Texture &texture, float x, float y, float r, float g, float b, float a);
    void draw(Texture &texture, int width, int height, float x, float y, float r, float g, float b, float a);
};


#endif //DARKNESS_SPRITEBATCH_H
