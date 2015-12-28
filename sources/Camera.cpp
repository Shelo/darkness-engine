#include "Camera.h"

Camera::Camera(int width, int height) :
        projection(glm::ortho(0.0f, (float) width, 0.0f, (float) height))
{

}

glm::mat4 Camera::getProjectedView()
{
    return projection * glm::translate(glm::mat4(1.0f), glm::vec3(position, 0) * -1.0f);
}
