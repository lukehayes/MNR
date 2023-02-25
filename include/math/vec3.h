#ifndef MATH_VEC3_H
#define MATH_VEC3_H

typedef struct Vec3
{
  float x;
  float y;
  float z;
  float w;

} Vec3;


/**
 * Create a new Vec3 with specified values.
 *
 * @param float x.
 * @param float y.
 * @param float z.
 *
 * @return Vec3.
 */
Vec3 Vec3Create(float x, float y, float z);

/**
 * Create a Vec3 with all values set to zero.
 *
 * @return Vec3.
 */
Vec3 Vec3Zero();

/**
 * Create a Vec3 with all of the values set to one.
 *
 * @return Vec3.
 */
Vec3 Vec3One();

/**
 * Get the length/magnitude of a Vec3.
 *
 * @param Vec3 v.
 *
 * @return Vec3.
 */
int Vec3Length(Vec3 v);

/**
 * Print a Vec3 to stdout.
 *
 * @return Vec3.
 */
void Vec3Print(Vec3 v);

#endif // MATH_VEC3_H
