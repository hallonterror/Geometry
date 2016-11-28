#pragma once

#include "Matrix.h"
#include "Vector.h"

namespace dry
{
  template <typename T>
  Matrix3<T> getRotation(const Matrix3x4<T>& C)
  {
    return Matrix3<T>(
      C.a00, C.a10, C.a20,
      C.a01, C.a11, C.a21,
      C.a02, C.a12, C.a22);
  }
  template <typename T>
  Vector3<T> getPosition(const Matrix3x4<T>& C)
  {
    return Vector3<T>(
      -C.a00*C.a03 - C.a10*C.a13 - C.a20*C.a23,
      -C.a01*C.a03 - C.a11*C.a13 - C.a21*C.a23,
      -C.a02*C.a03 - C.a12*C.a13 - C.a22*C.a23 );
  }
  template <typename T>
  Matrix3x4<T> getCameraMatrix(const Matrix3<T>& R, const Vector3<T>& t)
  {
    return Matrix3x4<T>(
      R.a00, R.a10, R.a20, -R.a00*t.x - R.a10*t.y - R.a20*t.z,
      R.a01, R.a11, R.a21, -R.a01*t.x - R.a11*t.y - R.a21*t.z,
      R.a02, R.a12, R.a22, -R.a02*t.x - R.a12*t.y - R.a22*t.z);
  }
}