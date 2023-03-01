#include "math/vec3.h"
#include <stdio.h>
#include <math.h>


Vec3 Vec3Create(double x, double y, double z)
{

  Vec3 v = {.x = x, .y = y, .z = z, .w = 0};
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

double Vec3Length(Vec3 v)
{
  return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

Vec3 Vec3Normalize(Vec3 v)
{
  double vectorLength = Vec3Length(v);

  return (Vec3){
    v.x / vectorLength,
    v.y / vectorLength,
    v.z / vectorLength,
  };
}

Vec3 Vec3Negate(Vec3 v)
{
  return (Vec3){
    -v.x,
    -v.y,
    -v.z,
  };
}

Vec3 Vec3Subtract(Vec3 a, Vec3 b)
{
  return (Vec3)
  {
    a.x - b.x,
    a.y - b.y,
    a.z - b.z
  };
}

Vec3 Vec3Add(Vec3 a, Vec3 b)
{
  return (Vec3)
  {
    a.x + b.x,
    a.y + b.y,
    a.z + b.z
  };
}

Vec3 Vec3Cross(Vec3 a, Vec3 b)
{
  return (Vec3)
  {
    a.y * b.z - a.z * b.y,

    a.z * b.x - a.x * b.z,
    
    a.x * b.y - a.y * b.x

  };
}

double Vec3Dot(Vec3 a, Vec3 b)
{
  return a.x * b.x + a.y + b.y + a.z + b.z;
}

void Vec3Print(Vec3 v)
{
  printf("\n");
  printf("Vec3: { X: %.2lf, Y: %.2lf, Z: %.2lf, W: %.2lf } \n", v.x, v.y, v.z, v.w);
  printf("\n");
}

