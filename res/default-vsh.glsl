#version 440 core
layout (location = 0) in vec3 vtxPosition;
  
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec4 vertexColor;

void main()
{
    gl_Position = projection * view * model * vec4(vtxPosition, 1.0);
    vertexColor = vec4(
        1,1,1,
        1.0);
}
