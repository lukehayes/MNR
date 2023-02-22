#ifndef GFX_SHADER_H
#define GFX_SHADER_H

#include "common/types.h"

typedef struct Shader
{
  GLuint program;
  const char* vertex_shader_path;
  const char* fragment_shader_path;

} Shader;

/**
 * Create a shader struct using the path to the vertex
 * and fragment shaders.
 *
 * @param const char * vtx_path
 * @param const char * frag_path
 *
 * @return Shader
 */
Shader gfxShaderCreate(const char* vtx_path, const char* frag_path);

// static void gfxShaderCheckErrors(unsigned int shader, const char* type);

#endif
