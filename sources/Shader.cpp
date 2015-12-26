#include "Shader.h"

Shader::Shader(std::string vertex, std::string fragment)
{
    program = glCreateProgram();

    createShader(vertex, GL_VERTEX_SHADER);
    createShader(fragment, GL_FRAGMENT_SHADER);

    glLinkProgram(program);

    // TODO: check link status.

    glValidateProgram(program);
}

void Shader::createShader(std::string code, GLenum type)
{
    GLuint shader = glCreateShader(type);

    if (shader == 0) {
        ERROR("Shader creation failed.")
    }

    const GLchar *source = code.c_str();

    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    // TODO: check is shader compiled.

    glAttachShader(program, shader);
}

GLuint Shader::getUniformLocation(std::string uniform)
{
    GLuint location = 0;
    if (uniforms.find(uniform) == uniforms.end()) {
        GLint l = glGetUniformLocation(program, uniform.c_str());

        if (l != -1) {
            uniforms[uniform] = location = (GLuint) l;
        } else {
            ERROR("Uniform " + uniform + " does not exists.")
        }
    } else {
        location = uniforms[uniform];
    }

    return location;
}

void Shader::setUniform(std::string uniform, glm::mat3 matrix)
{
    glUniformMatrix3fv(getUniformLocation(uniform), 1, GL_FALSE, glm::value_ptr(matrix));
}
