#version 330 core

layout (location = 0) in vec2 a_position;
layout (location = 1) in vec2 a_texCoord;
layout (location = 2) in vec4 a_color;

uniform mat4 u_projectedView;

out vec4 color;
out vec2 texCoord;

void main() {
    vec4 position = u_projectedView * vec4(a_position, 0, 1.0);
    gl_Position = position;

    color = a_color;
    texCoord = a_texCoord;
}
