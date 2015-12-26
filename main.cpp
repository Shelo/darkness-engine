#include <iostream>

#include "Application.h"

void mainloop(float elapsed)
{

}

int main() {
    Application application(mainloop);
    application.start(60, 900, 600, "My application");
    return 0;
}
