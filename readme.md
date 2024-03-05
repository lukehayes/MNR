# MNR - (readme from AxMath)

I wanted to teach myself Linear Algebra so this library represents my journey with that.

The library is primary designed to be used with game programming and is aimed at
being a simple, minimal replacement for something like CGLM etc.


## Included Types

##### Vec3
```c
typedef struct Vec3
{
  double x;
  double y;
  double z;
  double w;

} Vec3;

// Create a Vector3 with all components set to one.
Vec3 vec = Vec3One();
```

#### Mat4
```c
typedef struct Mat4
{
  // Represents a column major matrix;
  double m0, m4, m8,  m12,
        m1, m5, m9,  m13,
        m2, m6, m10, m14,
        m3, m7, m11, m15;

} Mat;

// Create an identity matrix.
M4 mat = Mat4Identity();
```
