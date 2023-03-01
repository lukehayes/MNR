#ifndef MATH_VEC3_H
#define MATH_VEC3_H

typedef struct Vec3
{
  double x;
  double y;
  double z;
  double w;

} Vec3;


/**
 * Create a new Vec3 with specified values.
 *
 * @param double x.
 * @param double y.
 * @param double z.
 *
 * @return Vec3.
 */
Vec3 Vec3Create(double x, double y, double z);

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
double Vec3Length(Vec3 v);

/**
 * Normalize a Vec3 - reduce its length to 1 (a unit vector).
 *
 * @param Vec3 v.
 *
 * @return Vec3.
 */
Vec3 Vec3Normalize(Vec3 v);

/**
 * Minus every value inside the Vec3 and return a new Vec3.
 *
 * @param Vec3 v.
 *
 * @return Vec3.
 */
Vec3 Vec3Negate(Vec3 v);

/**
 * Subtract one Vec3 from another.
 *
 * @param Vec3 a.
 * @param Vec3 b.
 *
 * @return Vec3
 */
Vec3 Vec3Subtract(Vec3 a, Vec3 b);

/**
 * Add one Vec3 to another.
 *
 * @param Vec3 a.
 * @param Vec3 b.
 *
 * @return Vec3
 */
Vec3 Vec3Add(Vec3 a, Vec3 b);

/**
 * Get the cross product of two vectors.
 *
 * @param Vec3 a.
 * @param Vec3 b.
 *
 * @return Vec3
 */
Vec3 Vec3Cross(Vec3 a, Vec3 b);

/**
 * Get the dot product of two vectors.
 *
 * @param Vec3 a.
 * @param Vec3 b.
 *
 * @return double.
 */
double Vec3Dot(Vec3 a, Vec3 b);

/**
 * Print a Vec3 to stdout.
 *
 * @return Vec3.
 */
void Vec3Print(Vec3 v);

#endif // MATH_VEC3_H
