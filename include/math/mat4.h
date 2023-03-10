#ifndef MATH_MAT4_H
#define MATH_MAT4_H

typedef struct Mat4
{
  float values[4][4];

} Mat4;

/**
 * Create a Mat4 with all values set to zero.
 *
 * @return Mat4.
 */
Mat4 Mat4Zero();

/**
 * Create a Mat4 indentity matrix.
 *
 * @return Mat4.
 */
Mat4 Mat4Identity();

/**
 * Print a Mat4 to stdout.
 *
 * @return Mat4.
 */
void Mat4Print(Mat4* matrix);

#endif // MATH_MAT4_H
