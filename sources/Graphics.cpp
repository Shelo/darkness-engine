#include "Graphics.h"

Graphics::Graphics(int width, int height, const std::string title) :
        width(width),
        height(height),
        title(title)
{
    // initialize components and libraries.
    if (!glfwInit()) {
        ERROR("GLFW not initialized");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (window == nullptr) {
        ERRORC("Window could not be created.", {
            glfwTerminate();
        })
    }

    // center the window on the screen.
    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (mode->width - width) / 2, (mode->height - height) / 2);

    // make this the current opengl context.
    glfwMakeContextCurrent(window);

    // create the default shader.
    shader.reset(new Shader(readFile("resources/vertex.glsl"), readFile("resources/fragment.glsl")));

    glClearColor(0, 0, 0, 0);
}

void Graphics::update()
{
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}

bool Graphics::isCloseRequested()
{
    return (bool) glfwWindowShouldClose(window);
}
