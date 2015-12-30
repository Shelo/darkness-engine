#include "Application.h"

#include "game/Game.h"

template <class T>
void Application<T>::start(float fps, int width, int height, const std::string title)
{
    // do not start again.
    if (daemon)
        return;

    // save the time that should take one frame.
    frameTime = 1.0f / fps;

    // start the daemon.
    daemon = true;

    // create the graphics driver as a unique ptr.
    graphics.reset(new Graphics(width, height, title, [=] ()
    {
        context->render();
    }));

    // securely, call the context creation.
    context.reset(new T());

    context->setGraphics(graphics);

    LOG("Application created")

    // finally run the application until the daemon dies.
    run();
}

template <class T>
void Application<T>::run()
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
            step((float) frameTime);

            lag -= frameTime;
        }

        if (graphics->isCloseRequested()) {
            daemon = false;
        }
    }
}

template <class T>
void Application<T>::step(float elapsed)
{
    context->update(elapsed);
    graphics->update();

    // input();
}


template <class T>
Application<T>::~Application()
{
    glfwTerminate();
}

template class Application<Game>;