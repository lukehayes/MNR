#include "glad/glad.h"
#include "gfx/shader.h"
#include "common/types.h"
#include "io/fileio.h"
#include <stdio.h>
#include <string.h>

static void gfxShaderCheckErrors(unsigned int shader, const char* type)
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

  printf("No Error Found\n");
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
Shader gfxShaderCreate(const char* vtx_path, const char* frag_path)
{
  Shader shader;

  unsigned int vertex, fragment;

  const char* const vsh_contents = ReadFile(vtx_path);
  const char* const fsh_contents = ReadFile(frag_path);

  // Create Vertex Shader
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vsh_contents, NULL);
  glCompileShader(vertex);
  gfxShaderCheckErrors(vertex, "VERTEX");

  // Create Fragment Shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fsh_contents, NULL);
  glCompileShader(fragment);
  gfxShaderCheckErrors(fragment, "FRAGMENT");

  // Create Shader Program
  shader.program = glCreateProgram();
  glAttachShader(shader.program, vertex);
  glAttachShader(shader.program, fragment);
  glLinkProgram(shader.program);
  gfxShaderCheckErrors(shader.program, "PROGRAM");

  // delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);

  free((char*)vsh_contents);
  free((char*)fsh_contents);

  return shader;
}

void gfxShaderUniform1f(const char* name, float value, Shader* shader)
{
  int shaderLocation = glGetUniformLocation(shader->program, name);
  glUniform1f(shaderLocation, value);
}

void gfxShaderUniform2f(const char* name, float v1, float v2, Shader* shader)
{
  int shaderLocation = glGetUniformLocation(shader->program, name);
  glUniform2f(shaderLocation, v1, v2);
}

void gfxShaderUniform3f(const char* name, float v1, float v2, float v3, Shader* shader)
{
  int shaderLocation = glGetUniformLocation(shader->program, name);
  glUniform3f(shaderLocation, v1, v2, v3);
}

void gfxShaderSendUniformMat4(Shader* shader, Mat4* matrix, const char* name)
{
  double matrixArray[16];
  GLuint uniformLocation = glGetUniformLocation(shader->program, name);
  glUniformMatrix4fv(uniformLocation, 1, GL_TRUE, (float*)Mat4ToArray(matrix, matrixArray));
}

void gfxShaderDestroy(Shader* shader)
{
  glDeleteProgram(shader->program);
}
