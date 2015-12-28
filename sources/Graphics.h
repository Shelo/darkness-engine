#ifndef DARKNESS_GRAPHICS_H
#define DARKNESS_GRAPHICS_H


#include <string>

#define GLFW_INCLUDE_GLCOREARB
#include "GLFW/glfw3.h"

#include "Macros.h"
#include "Shader.h"
#include "Util.h"
#include "SpriteBatch.h"
#include "Camera.h"


class Graphics
{
private:
    /** Width of the created window (in pixels). */
    int width;

    /** Height of the created window (in pixels). */
    int height;

    /** Title for the window. */
    std::string title;

    /** GLFW Window object. */
    GLFWwindow *window;

    /** Shader program. */
    std::unique_ptr<Shader> shader;

    /** Default sprite batch. */
    std::unique_ptr<SpriteBatch> batch;

    /** Renderer callback. */
    std::function<void()> renderer;

    /** Default camera. */
    Camera camera;

    /**
     * Prepare render status and render.
     */
    void render();

    /**
     * Setup OpenGL.
     */
    void setupGL();

public:
    /**
     * Create a graphics driver.
     *
     * @param width     width for the window in pixels.
     * @param height    height for the window in pixels.
     * @param title     title for the window.
     */
    Graphics(int width, int height, const std::string title, std::function<void()> renderer);

    /**
     * Update events and buffer of the window.
     */
    void update();

    /**
     * Check if the window should close.
     */
    bool isCloseRequested();

    /**
     * Returns the default sprite batch.
     */
    SpriteBatch &getSpriteBatch() const;

    /**
     * Returns the default camera.
     */
    Camera &getCamera();
};


#endif //DARKNESS_GRAPHICS_H
