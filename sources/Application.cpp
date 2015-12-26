#include "Application.h"


Application::Application(std::function<void(float)> mainloop) :
        mainloop(mainloop)
{

}

void Application::start(float fps, int width, int height, const std::string title)
{
    // do not start again.
    if (daemon)
        return;

    // save the time that should take one frame.
    frameTime = 1.0f / fps;

    // start the daemon.
    daemon = true;

    // create the graphics driver as a unique ptr.
    graphics.reset(new Graphics(width, height, title));

    // finally run the application until the daemon dies.
    run();
}

void Application::run()
{
    double current;
    double elapsed;
    double previous = glfwGetTime();
    double lag = 0;
    double delta = 0;

    // the only way of stopping the application is by killing the daemon.
    while (daemon) {
        current = glfwGetTime();
        elapsed = current - previous;
        previous = current;
        lag += elapsed;
        delta += elapsed;

        while (lag >= frameTime) {
            // update the game.
            step((float) delta);

            lag -= frameTime;

            // since the game was updated, the delta should be restarted
            // to count for the next frame.
            delta = 0;
        }

        if (graphics->isCloseRequested()) {
            daemon = false;
        }
    }
}

void Application::step(float elapsed)
{
    mainloop(elapsed);
    graphics->update();
    // input();
}

Application::~Application()
{
    glfwTerminate();
}
