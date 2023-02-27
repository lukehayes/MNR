#ifndef MATH_MAT4_H
#define MATH_MAT4_H

#include "math/vec3.h"

typedef struct Mat4
{
  // Represents a column major matrix;
  float m0, m4, m8,  m12,
        m1, m5, m9,  m13,
        m2, m6, m10, m14,
        m3, m7, m11, m15;

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

/* -----------------------------------------------------------------------------
  Matrix Creation
------------------------------------------------------------------------------*/

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


/* -----------------------------------------------------------------------------
  Matrix Projection
------------------------------------------------------------------------------*/

/**
 * Create an orthographic projection matrix.
 *
 * @return Mat4.
 */
Mat4 Mat4OrthoProjection(OrthoProjection* proj);

/**
 * Create an orthographic projection matrix.
 *
 * @return Mat4.
 */
Mat4 Mat4LookAt(Vec3 eye, Vec3 target, Vec3 up);


/**
 * Create a translation matrix. 
 *
 * @return Mat4.
 */
void Mat4Translate(Mat4* m, Vec3 v);

/* -----------------------------------------------------------------------------
  Matrix Math
------------------------------------------------------------------------------*/

/**
 * Multiply a Mat4 by a Vec3.
 *
 * @param Mat4* m.
 * @param Vec3 v.
 *
 * @return void.
 */
void Mat4MultVec(Mat4* m, Vec3 vec);

/**
 * Get a specific value from a Mat4 matrix in COLUMN MAJOR order.
 *
 * @return float.
 */
float Mat4GetValue(const Mat4* m, int column, int row);

/* -----------------------------------------------------------------------------
  Printing Utility Functions
------------------------------------------------------------------------------*/

/**
 * Print a Mat4 to stdout.
 *
 * @return Mat4.
 */
void Mat4Print(Mat4 matrix);

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
