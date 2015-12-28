#ifndef DARKNESS_APPLICATION_H
#define DARKNESS_APPLICATION_H

#include <functional>
#include <iostream>

#include "Graphics.h"
#include "Context.h"

class Application {
private:
    /** The initialization handle. */
    std::unique_ptr<Context> context;

    /** The time that one frame should take. */
    double frameTime;

    /** Tells if the application should continue or stop when possible. */
    bool daemon;

    /**
     * Application's running state, this updates the game and graphics while
     * calculating delta times. The daemon should be killed in order to stop
     * the running state.
     */
    void run();

    /**
     * The graphics driver.
     */
    std::shared_ptr<Graphics> graphics;

public:
    /**
     * Creates the application and sets the state handles.
     *
     * @param mainloop      the update handle.
     */
    Application(Context *context);

    ~Application();

    /**
     * Start the application at the given frame rate.
     *
     * @param fps   maximum frames per second.
     */
    void start(float fps, int width, int height, const std::string title);

    /**
     * Updates the game (just one frame).
     *
     * @param elapsed   frame's delta time.
     */
    void step(float elapsed);
};


#endif //DARKNESS_APPLICATION_H
