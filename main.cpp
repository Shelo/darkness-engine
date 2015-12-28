#include <iostream>

#include "Application.h"

Texture *moka;

void initialize()
{
    moka = new Texture("resources/moka.png");
}

void render(Graphics *graphics)
{
    graphics->getCamera().position.x -= 1;

    graphics->getSpriteBatch().draw(*moka, 0, 0, 1, 1, 1, 1);
    graphics->getSpriteBatch().draw(*moka, 50 * 1, 0, 1, 1, 1, 1);
    graphics->getSpriteBatch().draw(*moka, 50 * 2, 0, 1, 1, 1, 1);
    graphics->getSpriteBatch().draw(*moka, 50 * 3, 0, 1, 1, 1, 1);
}

void mainloop(float elapsed)
{

}

int main() {
    Application application(initialize, mainloop, render);
    application.start(30, 900, 600, "My application");

    delete moka;

    return 0;
}
