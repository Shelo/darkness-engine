#include "Shader.h"

void checkStatus(GLuint target, GLenum param, void (*check) (GLuint, GLenum, GLsizei *),
                 void (*log) (GLuint, GLsizei, GLsizei *, GLchar *))
{
    GLsizei status;

    check(target, param, &status);

    if (status == GL_FALSE) {
        char buffer[512];
        GLsizei length;

        log(target, 512, &length, buffer);

        ERROR(buffer)
    }
}

Shader::Shader(std::string vertex, std::string fragment)
{
    program = glCreateProgram();

    createShader(vertex, GL_VERTEX_SHADER);
    createShader(fragment, GL_FRAGMENT_SHADER);

    glLinkProgram(program);
    checkStatus(program, GL_LINK_STATUS, glGetProgramiv, glGetProgramInfoLog);

    // create a dummy vao for validation of this shader.
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glValidateProgram(program);
    checkStatus(program, GL_VALIDATE_STATUS, glGetProgramiv, glGetProgramInfoLog);

    LOG("Shader created.")
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
    checkStatus(shader, GL_COMPILE_STATUS, glGetShaderiv, glGetShaderInfoLog);

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

void Shader::bind()
{
    glUseProgram(program);
}
