#include <iostream>

#include "Darkness.h"
#include "game/Game.h"

int main() {
    Application<Game> application;
    application.start(30, 900, 600, "Darkness");

    return 0;
}
