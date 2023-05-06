#ifndef GFX_MESH_H
#define GFX_MESH_H

/**
 * Single location to store all of the mesh data.
 */
typedef struct Mesh
{
  float quad_verticies[12];
  int quad_indicies[6];
  int quad_vertex_count;
  int quad_index_count;

} Mesh;


/**
 * Initialize a Mesh struct with basic vertex and index data.
 *
 * @return Mesh.
 */
Mesh CreateMeshFactory()
{
  Mesh mesh = {
    .quad_verticies = {
       0.5f,  0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,
      -0.5f, -0.5f, 0.0f,
      -0.5f,  0.5f, 0.0f   
    },

    .quad_indicies = {
      0,1,3,
      1,2,3
    },

    .quad_vertex_count = 12,
    .quad_index_count = 6
  };

  return mesh;
}



#endif // !GFX_MESH_H
