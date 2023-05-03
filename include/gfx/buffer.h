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

Buffer CreateGLBuffer(float verticies[], int vert_count, int indicies[], int idx_count)
{
  Buffer buffer;
  buffer.vert_count = vert_count;
  buffer.idx_count  =  idx_count;
  buffer.bufferType = GL_ARRAY_BUFFER;


  glGenVertexArrays( 1, &buffer.vao );
  glBindVertexArray( buffer.vao );

  glGenBuffers( 1, &buffer.vbo);
  glBindBuffer( GL_ARRAY_BUFFER, buffer.vbo);

  glEnableVertexAttribArray( 0 );
  glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0 );
  glBufferData( GL_ARRAY_BUFFER, sizeof(float) * buffer.vert_count , verticies, GL_STATIC_DRAW );

  // INDEX BUFFER
  glGenBuffers( 1, &buffer.ibo );
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, buffer.ibo );
  glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * buffer.idx_count , indicies, GL_STATIC_DRAW );

  return buffer;
}

#endif // !GFX_BUFFER_H
