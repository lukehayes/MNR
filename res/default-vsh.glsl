#version 440 core
layout (location = 0) in vec3 vtxPosition;
  
out vec4 vertexColor;

void main()
{
    gl_Position = vec4(vtxPosition, 1.0);
    vertexColor = vec4(
        1,1,1,
        1.0);
}
