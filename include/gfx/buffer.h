#ifndef GFX_BUFFER_H
#define GFX_BUFFER_H

#include <glad/glad.h>

/**
 * A single location to store all of the 
 * buffer related data.
 */
typedef struct Buffer
{
  GLuint vao;
  GLuint vbo;
  GLuint ibo;
  int vert_count;
  int idx_count;
  GLenum bufferType;

}Buffer;

Buffer CreateGLBuffer(float verticies[], int vert_count, int indicies[], int idx_count);

void GenVertexArray(int count, Buffer* buffer);

void GenVertexBuffer(int count, GLenum bufferType, Buffer* buffer);

void SetAttribData(int location, int vert_count, float verticies[], Buffer* buffer);

void GenIndexBuffer(int count, GLenum bufferType, int indicies[], Buffer* buffer);

#endif // !GFX_BUFFER_H
