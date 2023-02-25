#include "math/mat4.h"
#include <stdio.h>

Mat4 Mat4Zero()
{
  Mat4 matrix;

  for(int i = 0; i <= 3; i++)
  {
    for(int j = 0; j <= 3; j++)
    {
      matrix.values[i][j] = 0;
    }
  }

  return matrix;
}

Mat4 Mat4Identity()
{
  Mat4 matrix = Mat4Zero();

  matrix.values[0][0] = 1.0;
  matrix.values[1][1] = 1.0;
  matrix.values[2][2] = 1.0;
  matrix.values[3][3] = 1.0;

  return matrix;
}

Mat4 Mat4OrthoProjection(OrthoProjection* proj)
{
  Mat4 matrix = Mat4Identity();

  matrix.values[0][0] =  2 / (proj->right - proj->left);
  matrix.values[1][1] =  2 / (proj->top   - proj->bottom);
  matrix.values[2][2] = -2 / (proj->far   - proj->near);

  matrix.values[3][0] = -(proj->right + proj->left   / proj->right - proj->left );
  matrix.values[3][1] = -(proj->top   + proj->bottom / proj->top   - proj->bottom );
  matrix.values[3][2] = -(proj->far   + proj->near   / proj->far   - proj->near );
  matrix.values[3][3] = 1;

  return matrix;
}

Mat4 Mat4LookAt(Vec3 eye, Vec3 target, Vec3 up)
{
  Vec3 zaxis = normalize(target - eye);    
  Vec3 xaxis = normalize(cross(zaxis, up));
  Vec3 yaxis = cross(xaxis, zaxis);

  negate(zaxis);

  mat4 viewMatrix = {
    vec4(xaxis.x, xaxis.y, xaxis.z, -dot(xaxis, eye)),
    vec4(yaxis.x, yaxis.y, yaxis.z, -dot(yaxis, eye)),
    vec4(zaxis.x, zaxis.y, zaxis.z, -dot(zaxis, eye)),
    vec4(0, 0, 0, 1)
  };

  return viewMatrix;
}

void Mat4Translate(Mat4* m, Vec3 v)
{
  m->values[3][0] = v.x;
  m->values[3][1] = v.y;
  m->values[3][2] = v.z;
  m->values[3][3] = 1;
}

void Mat4MultVec(Mat4* m, Vec3 vec)
{
  m->values[0][0] = m->values[0][0] * vec.x;
  m->values[0][1] = m->values[0][1] * vec.x;
  m->values[0][2] = m->values[0][2] * vec.x;
  m->values[0][3] = m->values[0][3] * vec.x;
                                   
  m->values[1][0] = m->values[1][0] * vec.y;
  m->values[1][1] = m->values[1][1] * vec.y;
  m->values[1][2] = m->values[1][2] * vec.y;
  m->values[1][3] = m->values[1][3] * vec.y;
                                   
  m->values[2][0] = m->values[2][0] * vec.z;
  m->values[2][1] = m->values[2][1] * vec.z;
  m->values[2][2] = m->values[2][2] * vec.z;
  m->values[2][3] = m->values[2][3] * vec.z;
                                   
  m->values[3][0] = m->values[3][0] * vec.w;
  m->values[3][1] = m->values[3][1] * vec.w;
  m->values[3][2] = m->values[3][2] * vec.w;
  m->values[3][3] = m->values[3][3] * vec.w;

}

float Mat4GetValue(const Mat4* m, int column, int row)
{
  return m->values[column][row];
}

void Mat4Print(Mat4 matrix)
{
  printf("\n");
  printf("Mat4 \n");
  for(int i = 0; i <= 3; i++)
  {
    for(int j = 0; j <= 3; j++)
    {
      if(j < 3)
      {
        printf("| %.2f,", matrix.values[j][i]);
      }else
      {
        printf("| %.2f", matrix.values[j][i]);
        printf("|\n");
      }
    }
  }
  printf("\n");
}

void Mat4PrintValue(Mat4* mat,int x, int y)
{
  printf("Matrix Value: %f \n", mat->values[x][y]);
}

