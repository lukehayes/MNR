#include "gfx/buffer.h"

Buffer CreateGLBuffer(float verticies[], int vert_count, int indicies[], int idx_count)
{
  Buffer buffer;
  buffer.vert_count = vert_count;
  buffer.idx_count  =  idx_count;
  buffer.bufferType = GL_ARRAY_BUFFER;

  GenVertexArray(1, &buffer);
  GenVertexBuffer(1, GL_ARRAY_BUFFER, &buffer);
  SetAttribData(0, 12, verticies, &buffer);
  GenIndexBuffer(1, GL_ELEMENT_ARRAY_BUFFER, indicies, &buffer);

  return buffer;
}

void GenVertexArray(int count, Buffer* buffer)
{
  glGenVertexArrays( 1, &buffer->vao );
  glBindVertexArray( buffer->vao );
}

void GenVertexBuffer(int count, GLenum bufferType, Buffer* buffer)
{
  glGenBuffers( 1, &buffer->vbo);
  glBindBuffer( bufferType, buffer->vbo);
}

void SetAttribData(int location, int vert_count, float verticies[], Buffer* buffer)
{
  glEnableVertexAttribArray( location );
  glVertexAttribPointer( location, 3, GL_FLOAT, GL_FALSE, 0, 0 );
  glBufferData( GL_ARRAY_BUFFER, sizeof(float) * buffer->vert_count , verticies, GL_STATIC_DRAW );
}

void GenIndexBuffer(int count, GLenum bufferType, int indicies[], Buffer* buffer)
{
  glGenBuffers( count, &buffer->ibo );
  glBindBuffer( bufferType, buffer->ibo );
  glBufferData( bufferType, sizeof(int) * buffer->idx_count , indicies, GL_STATIC_DRAW );
}
