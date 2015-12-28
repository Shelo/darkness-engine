#include <iostream>

#include "Darkness.h"

class Game : public Context
{
private:
    Sprite moka;

public:
    Game() :
            moka("resources/moka.png", 0, 0)
    {

    }

    void create()
    {
        moka.load();
    }

    void render()
    {
        moka.render(&*graphics);
    }

    void update(float delta)
    {
        graphics->getCamera().position -= 2;
    }
};

int main() {
    Application application(new Game());
    application.start(30, 900, 600, "My application");

    return 0;
}
