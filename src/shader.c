#include "glad/glad.h"
#include "gfx/shader.h"
#include "common/types.h"
#include "io/fileio.h"
#include <stdio.h>
#include <string.h>

void gfxCheckCompileErrors(unsigned int shader, const char* type)
{
  printf("Checking Shader Errors \n");
  int success;
  char infoLog[1024];
  if (strcmp(type, "PROGRAM") == 0)
  {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      printf("SHADER_COMPILATION_ERROR: %s \n %s \n -- \n", type, infoLog);
    }
  }
  else
  {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success)
    {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      printf("SHADER_LINKING_ERROR: %s \n %s \n -- \n", type, infoLog);
    }
  }
}

/**
 * Create a shader struct using the path to the vertex
 * and fragment shaders.
 *
 * @param const char * vtx_path
 * @param const char * frag_path
 *
 * @return Shader
 */
Shader gfxCreateShader(const char* vtx_path, const char* frag_path)
{
  Shader shader;
  shader.vertex_shader_path = vtx_path;
  shader.fragment_shader_path = frag_path;

  unsigned int vertex, fragment;

  const char* const vsh_contents = ReadFile(vtx_path);
  const char* const fsh_contents = ReadFile(frag_path);

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vsh_contents, NULL);
  glCompileShader(vertex);
  gfxCheckCompileErrors(vertex, "VERTEX");

  // fragment Shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fsh_contents, NULL);
  glCompileShader(fragment);
  gfxCheckCompileErrors(fragment, "FRAGMENT");

  // shader Program
  shader.program = glCreateProgram();
  glAttachShader(shader.program, vertex);
  glAttachShader(shader.program, fragment);
  glLinkProgram(shader.program);
  gfxCheckCompileErrors(shader.program, "PROGRAM");
  // delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);

  free((char*)vsh_contents);
  free((char*)fsh_contents);

  return shader;
}
