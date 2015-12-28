#include <OpenGL/gl3.h>

#include "SpriteBatch.h"
#include "glm/glm.hpp"

SpriteBatch::SpriteBatch() :
        vertices(VERTEX_BUFFER_SIZE),
        indices(INDEX_BUFFER_SIZE),
        ibc(0),
        vbc(0),
        vertexCounter(0)
{
    glGenVertexArrays(1, &vao);

    glGenBuffers(1, &ibo);
    glGenBuffers(1, &vbo);
}

void SpriteBatch::draw(Texture &texture, float x, float y, float r, float g, float b, float a)
{
    draw(texture, texture.getWidth(), texture.getHeight(), x, y, r, g, b, a);
}

void SpriteBatch::draw(Texture &texture, int width, int height, float x, float y,
        float r, float g, float b, float a)
{
    setTexture(texture);

    if (vbc >= VERTEX_BUFFER_SIZE) {
        render();
    }

    vertices[vbc++] = x;
    vertices[vbc++] = y;
    vertices[vbc++] = 0;
    vertices[vbc++] = 1;
    vertices[vbc++] = r;
    vertices[vbc++] = g;
    vertices[vbc++] = b;
    vertices[vbc++] = a;

    vertices[vbc++] = x;
    vertices[vbc++] = y + height;
    vertices[vbc++] = 0;
    vertices[vbc++] = 0;
    vertices[vbc++] = r;
    vertices[vbc++] = g;
    vertices[vbc++] = b;
    vertices[vbc++] = a;

    vertices[vbc++] = x + width;
    vertices[vbc++] = y + height;
    vertices[vbc++] = 1;
    vertices[vbc++] = 0;
    vertices[vbc++] = r;
    vertices[vbc++] = g;
    vertices[vbc++] = b;
    vertices[vbc++] = a;

    vertices[vbc++] = x + width;
    vertices[vbc++] = y;
    vertices[vbc++] = 1;
    vertices[vbc++] = 1;
    vertices[vbc++] = r;
    vertices[vbc++] = g;
    vertices[vbc++] = b;
    vertices[vbc++] = a;

    indices[ibc++] = vertexCounter;
    indices[ibc++] = vertexCounter + 1;
    indices[ibc++] = vertexCounter + 2;
    indices[ibc++] = vertexCounter;
    indices[ibc++] = vertexCounter + 2;
    indices[ibc++] = vertexCounter + 3;

    vertexCounter += 4;
}

void SpriteBatch::render()
{
    if (vertexCounter == 0) {
        return;
    }

    texture->bind();

    glBindVertexArray(vao);

    // buffer vertices.
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vbc * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

    // position.
    glEnableVertexAttribArray(0);

    // texture coordinates.
    glEnableVertexAttribArray(1);

    // color.
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (void *) (sizeof(GLfloat) * 2));
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (void *) (sizeof(GLfloat) * 4));

    // buffer indices.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, ibc * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

    // draw as triangles.
    glDrawElements(GL_TRIANGLES, (GLsizei) ibc, GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0);

    // clean state.
    texture = nullptr;
    vbc = ibc = vertexCounter = 0;
}

void SpriteBatch::setTexture(Texture &texture)
{
    if (this->texture != nullptr && this->texture != &texture) {
        render();
    }

    this->texture = &texture;
}
