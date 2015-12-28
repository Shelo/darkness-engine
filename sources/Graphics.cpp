#include "Graphics.h"

Graphics::Graphics(int width, int height, const std::string title, std::function<void()> renderer) :
        width(width),
        height(height),
        title(title),
        renderer(renderer),
        camera(width, height)
{
    // initialize components and libraries.
    if (!glfwInit()) {
        ERROR("GLFW not initialized");
    }

    // set window hints and create the window.
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
    shader.reset(new Shader(readFile("resources/vertex_batch.glsl"),
            readFile("resources/fragment_batch.glsl")));

    // create the default sprite batch.
    batch.reset(new SpriteBatch());

    setupGL();

    LOG("Graphics driver created.")
}

void Graphics::update()
{
    render();

    glfwPollEvents();
    glfwSwapBuffers(window);
}

bool Graphics::isCloseRequested()
{
    return (bool) glfwWindowShouldClose(window);
}

void Graphics::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    shader->bind();

    shader->setUniform("u_projectedView", camera.getProjectedView());

    renderer();

    batch->render();
}

void Graphics::setupGL()
{
    glClearColor(0, 0, 0, 1);

    glFrontFace(GL_CW);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);

    LOG("GL Setup finished.")
}

SpriteBatch &Graphics::getSpriteBatch() const
{
    return *batch;
}

Camera &Graphics::getCamera()
{
    return camera;
}
