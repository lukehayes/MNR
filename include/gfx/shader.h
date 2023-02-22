#ifndef GFX_SHADER_H
#define GFX_SHADER_H

#include "common/types.h"

typedef struct Shader
{
  GLuint program;

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

/**
 * Delete the shader program.
 *
 * @param Shader* shader
 *
 * @return void
 */
void gfxShaderDestroy(Shader* shader);

// static void gfxShaderCheckErrors(unsigned int shader, const char* type);

#endif
