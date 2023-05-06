#ifndef GFX_SHADER_H
#define GFX_SHADER_H

#include "common/types.h"
#include "math/mat4.h"

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

/**
 * Send a single value float uniform value to the shader.
 *
 * @param const char* name.
 * @param float value.
 * @param Shader* shader.
 *
 * @return void
 */
void gfxShaderUniform1f(const char* name, float value, Shader* shader);

/**
 * Send two float uniform values to the shader.
 *
 * @param const char* name.
 * @param float v1.
 * @param float v2.
 *
 * @param Shader* shader.
 *
 * @return void
 */
void gfxShaderUniform2f(const char* name, float v1, float v2, Shader* shader);

/**
 * Send three float uniform values to the shader.
 *
 * @param const char* name.
 * @param float v1.
 * @param float v2.
 * @param float v3.
 *
 * @param Shader* shader.
 *
 * @return void
 */
void gfxShaderUniform3f(const char* name, float v1, float v2, float v3, Shader* shader);

/**
 * Send a mat4 value to the shader.
 *
 * @param const char* name.
 * @param Mat4 matrix.
 *
 * @param Shader* shader.
 *
 * @return void
 */
void gfxShaderSendUniformMat4(Shader* shader, Mat4* matrix, const char* name);

#endif
