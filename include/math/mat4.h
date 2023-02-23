#ifndef MATH_MAT4_H
#define MATH_MAT4_H

typedef struct Mat4
{
  float values[4][4];

} Mat4;

typedef struct OrthoProjection
{
  float top;
  float bottom;
  float left;
  float right;
  float near;
  float far;

} OrthoProjection;

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
 * Create an orthographic projection matrix.
 *
 * @return Mat4.
 */
Mat4 Mat4OrthoProjection(OrthoProjection* proj);

/**
 * Print a Mat4 to stdout.
 *
 * @return Mat4.
 */
void Mat4Print(Mat4* matrix);

/**
 * Print a specific Mat4 value to stdout.
 *
 * @param int x.
 * @param int y.
 *
 * @return Mat4.
 */
void Mat4PrintValue(Mat4* mat,int x, int y);

#endif // MATH_MAT4_H
