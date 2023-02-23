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

void Mat4Print(Mat4* matrix)
{
  printf("\n");
  printf("Mat4 \n");
  for(int i = 0; i <= 3; i++)
  {
    for(int j = 0; j <= 3; j++)
    {
      if(j < 3)
      {
        printf("| %.2f,", matrix->values[j][i]);
      }else
      {
        printf("| %.2f", matrix->values[j][i]);
        printf("|\n");
      }
    }
  }
  printf("\n");
}
