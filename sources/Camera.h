#ifndef DARKNESS_CAMERA_H
#define DARKNESS_CAMERA_H

#include "glm/gtc/matrix_transform.hpp"
#include "Macros.h"

class Camera
{
private:
    glm::mat4 projection;

public:
    glm::vec2 position;

    Camera(int width, int height);

    glm::mat4 getProjectedView();
};


#endif //DARKNESS_CAMERA_H
