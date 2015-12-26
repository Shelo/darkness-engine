#version 330 core

uniform sampler2D u_texture;
uniform vec4 u_color;

in vec2 texCoord;

out vec4 fragColor;

void main() {
    vec4 baseColor = texture(u_texture, texCoord);
    fragColor = baseColor * u_color;
}
