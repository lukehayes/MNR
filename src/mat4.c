#include "math/mat4.h"
#include <stdio.h>

Mat4 Mat4Zero()
{
  Mat4 matrix;

  matrix.m0  = 0;
  matrix.m1  = 0;
  matrix.m2  = 0;
  matrix.m3  = 0;

  matrix.m4  = 0;
  matrix.m5  = 0;
  matrix.m6  = 0;
  matrix.m7  = 0;

  matrix.m8  = 0;
  matrix.m9  = 0;
  matrix.m10 = 0;
  matrix.m11 = 0;

  matrix.m12 = 0;
  matrix.m13 = 0;
  matrix.m14 = 0;
  matrix.m15 = 0;

  return matrix;
}

Mat4 Mat4Identity()
{
  Mat4 matrix = Mat4Zero();

  matrix.m0  = 1.0;
  matrix.m5  = 1.0;
  matrix.m10 = 1.0;
  matrix.m15 = 1.0;

  return matrix;
}

Mat4 Mat4OrthoProjection(OrthoProjection* proj)
{
  Mat4 matrix = Mat4Identity();


  matrix.m0  =  2 / (proj->right - proj->left);
  matrix.m5  =  2 / (proj->top   - proj->bottom);
  matrix.m10 = -2 / (proj->far   - proj->near);

  matrix.m12 = -(proj->right + proj->left   / proj->right - proj->left );
  matrix.m13 = -(proj->top   + proj->bottom / proj->top   - proj->bottom );
  matrix.m14 = -(proj->far   + proj->near   / proj->far   - proj->near );
  matrix.m15 = 1;

  return matrix;
}

Mat4 Mat4LookAt(Vec3 eye, Vec3 target, Vec3 up)
{
  Vec3 zaxis = Vec3Normalize(Vec3Subtract(target, eye));
  Vec3 xaxis = Vec3Normalize(Vec3Cross(zaxis, up));
  Vec3 yaxis = Vec3Cross(xaxis, zaxis);

  zaxis = Vec3Negate(zaxis);

  // Mat4 viewMatrix = {
  //   vec4(xaxis.x, xaxis.y, xaxis.z, -dot(xaxis, eye)),
  //   vec4(yaxis.x, yaxis.y, yaxis.z, -dot(yaxis, eye)),
  //   vec4(zaxis.x, zaxis.y, zaxis.z, -dot(zaxis, eye)),
  //   vec4(0, 0, 0, 1)
  // };

  Mat4 vm = Mat4Identity();

  vm.m0  =  xaxis.x;
  vm.m1  =  xaxis.y;
  vm.m2  =  xaxis.z;
  vm.m3  =  -Vec3Dot(zaxis, eye);
                   

  vm.m4  =  yaxis.x;
  vm.m5  =  yaxis.y;
  vm.m6  =  yaxis.z;
  vm.m7  =  -Vec3Dot(yaxis, eye);

  vm.m8  =  zaxis.x;
  vm.m9  =  zaxis.y;
  vm.m10 =  zaxis.z;
  vm.m11 =  -Vec3Dot(zaxis, eye);

  vm.m12 =  0;
  vm.m13 =  0;
  vm.m14 =  0;
  vm.m15 =  1;

  return vm;
}

void Mat4Translate(Mat4* m, Vec3 v)
{
  m->m12 = v.x;
  m->m13 = v.y;
  m->m14 = v.z;
  m->m15 = 1.0;
}

void Mat4MultVec(Mat4* m, Vec3 vec)
{
  m->m0  = m->m0  * vec.x;
  m->m1  = m->m1  * vec.x;
  m->m2  = m->m2  * vec.x;
  m->m3  = m->m3  * vec.x;

  m->m4  = m->m4  * vec.y;
  m->m5  = m->m5  * vec.y;
  m->m6  = m->m6  * vec.y;
  m->m7  = m->m7  * vec.y;

  m->m8  = m->m8  * vec.z;
  m->m9  = m->m9  * vec.z;
  m->m10 = m->m10 * vec.z;
  m->m11 = m->m11 * vec.z;

  m->m12 = m->m12 * vec.w;
  m->m13 = m->m13 * vec.w;
  m->m14 = m->m14 * vec.w;
  m->m15 = m->m15 * vec.w;

}

float* Mat4ToArray(Mat4* m, float matrixArray[16])
{
    matrixArray[0]  = m->m0;
    matrixArray[1]  = m->m1;
    matrixArray[2]  = m->m2;
    matrixArray[3]  = m->m3;

    matrixArray[4]  = m->m4;
    matrixArray[5]  = m->m5;
    matrixArray[6]  = m->m6;
    matrixArray[7]  = m->m7;

    matrixArray[8]  = m->m8;
    matrixArray[9]  = m->m9;
    matrixArray[10] = m->m10;
    matrixArray[11] = m->m11;

    matrixArray[12] = m->m12;
    matrixArray[13] = m->m13;
    matrixArray[14] = m->m14;
    matrixArray[15] = m->m15;

    return matrixArray;
}


float Mat4GetValue(const Mat4* m, int column, int row)
{
  // return m->values[column][row];
}

// void Mat4Print(Mat4 matrix)
// {
//   printf("\n");
//   printf("Mat4 \n");
//   for(int i = 0; i <= 3; i++)
//   {
//     for(int j = 0; j <= 3; j++)
//     {
//       if(j < 3)
//       {
//         printf("| %.2f,", matrix.values[j][i]);
//       }else
//       {
//         printf("| %.2f", matrix.values[j][i]);
//         printf("|\n");
//       }
//     }
//   }
//   printf("\n");
// }
//
// void Mat4PrintValue(Mat4* mat,int x, int y)
// {
//   printf("Matrix Value: %f \n", mat->values[x][y]);
// }
//
