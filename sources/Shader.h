//
// Created by Marcelo Jara Almeyda on 12/26/15.
//

#ifndef DARKNESS_SHADER_H
#define DARKNESS_SHADER_H


#include <string>
#include <map>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "OpenGL/gl.h"
#include "Macros.h"


class Shader
{
private:
    GLuint program;
    std::map<std::string, GLuint> uniforms;

    void createShader(std::string code, GLenum type);
    GLuint getUniformLocation(std::string uniform);

public:
    Shader(std::string vertex, std::string fragment);

    void setUniform(std::string uniform, glm::mat3 matrix);
};


#endif //DARKNESS_SHADER_H
