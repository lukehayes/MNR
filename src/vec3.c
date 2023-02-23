#include "math/vec3.h"
#include <stdio.h>


Vec3 Vec3Create(float x, float y, float z)
{

  Vec3 v = {.x = x, .y = y, .z = z};
  return v;
}

Vec3 Vec3Zero()
{
  Vec3 v = {.x = 0, .y = 0, .z = 0};
  return v;
}

Vec3 Vec3One()
{
  Vec3 v = {.x = 1, .y = 1, .z = 1};
  return v;
}

void Vec3Print(Vec3* v)
{
  printf("\n");
  printf("Vec3 \n");

  printf("Vec3: { %.2f, %.2f, %.2f } \n", v->x, v->y, v->z);

  printf("\n");

}

