#version 440 core
layout (location = 0) in vec3 vtxPosition;
  
out vec4 vertexColor;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform float r;
uniform float g;
uniform float b;

void main()
{
    gl_Position = projection * view * model * vec4(vtxPosition, 1.0);
    vertexColor = vec4(
        clamp(r, 0.5,1.0),
        clamp(g, 0.5,1.0),
        clamp(b, 0.5,1.0),
        1.0);
}
