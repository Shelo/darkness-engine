#ifndef DARKNESS_GRAPHICS_H
#define DARKNESS_GRAPHICS_H


#include <string>

#include "GLFW/glfw3.h"
#include "OpenGL/gl.h"

#include "Macros.h"
#include "Shader.h"
#include "Util.h"


class Graphics
{
private:
    /**
     * Width of the created window (in pixels).
     */
    int width;

    /**
     * Height of the created window (in pixels).
     */
    int height;

    /**
     * Title for the window.
     */
    std::string title;

    /**
     * GLFW Window object.
     */
    GLFWwindow *window;

    /**
     * Shader program.
     */
    std::unique_ptr<Shader> shader;

public:
    /**
     * Create a graphics driver.
     *
     * @param width     width for the window in pixels.
     * @param height    height for the window in pixels.
     * @param title     title for the window.
     */
    Graphics(int width, int height, const std::string title);

    /**
     * Update events and buffer of the window.
     */
    void update();

    /**
     * Check if the window should close.
     */
    bool isCloseRequested();
};


#endif //DARKNESS_GRAPHICS_H
