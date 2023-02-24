#include "math/vec3.h"
#include <stdio.h>


Vec3 Vec3Create(float x, float y, float z)
{

  Vec3 v = {.x = x, .y = y, .z = z, .w = 1};
  return v;
}

Vec3 Vec3Zero()
{
  Vec3 v = {.x = 0, .y = 0, .z = 0, .w = 0};
  return v;
}

Vec3 Vec3One()
{
  Vec3 v = {.x = 1, .y = 1, .z = 1, .w = 1};
  return v;
}

void Vec3Print(Vec3 v)
{
  printf("\n");
  printf("Vec3: { X: %.2f, Y: %.2f, Z: %.2f, W:%.2f } \n", v.x, v.y, v.z, v.w);
  printf("\n");
}

