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
