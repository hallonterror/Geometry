#pragma once

#include "Matrix.h"
#include "Vector.h"
#include <math.h>

namespace dry
{
  // Special functions
  template <typename T>
  inline T det(const Matrix2<T>& mat)
  {
    return mat.a00 * mat.a11 - mat.a01 * mat.a10;
  }

  template <typename T>
  inline Matrix2<T> inverse(const Matrix2<T>& mat)
  {
    float64 invdet = 1.0 / det(mat);
    return Matrix2<T>(
       mat.a11 * invdet,
      -mat.a01 * invdet,
      -mat.a10 * invdet,
       mat.a00 * invdet);
  }

  template <typename T>
  inline Matrix2<T> transpose(const Matrix2<T>& mat)
  {
    return Matrix2<T>(mat.a00, mat.a10, mat.a01, mat.a11);
  }

  template <typename T>
  inline Matrix2<T> getRotation(const T& angle)
  {
    return Matrix2<T>(
      cos(angle), -sin(angle),
      sin(angle), cos(angle));
  }

  template <typename T>
  inline T det(const Matrix3<T>& mat)
  {
    return 
      mat.a00 * (mat.a11 * mat.a22 - mat.a21 * mat.a12) -
      mat.a01 * (mat.a10 * mat.a22 - mat.a12 * mat.a20) +
      mat.a02 * (mat.a10 * mat.a21 - mat.a11 * mat.a20);
  }

  template <typename T>
  inline Matrix3<T> getCrossMatrix(const Vector3<T>& vec)
  {
    return Matrix3<T>(
      0, -vec.z, vec.y,
      vec.z, 0, -vec.x,
      -vec.y, vec.x, 0);
  }

  template <typename T>
  inline Matrix3<T> getRotationEuler(const T& phi, const T& theta, const T& psi)
  {
    return Matrix3<T>(
      cos(psi)*cos(phi) - cos(theta)*sin(phi)*sin(psi),
      cos(psi)*sin(phi) + cos(theta)*cos(phi)*sin(psi),
      sin(psi)*sin(theta),

      -sin(psi)*cos(phi) - cos(theta)*sin(phi)*cos(psi),
      -sin(psi)*sin(phi) + cos(theta)*cos(phi)*cos(psi),
      cos(psi)*sin(theta),

      sin(theta)*sin(phi),
      -sin(theta)*cos(phi),
      cos(theta));
  }

  template <typename T>
  inline Matrix3<T> inverse(const Matrix3<T>& mat)
  {
    float64 invdet = 1.0 / det(mat);
    return Matrix3<T>(
      (mat.a11 * mat.a22 - mat.a21 * mat.a12) * invdet,
      (mat.a02 * mat.a21 - mat.a01 * mat.a22) * invdet,
      (mat.a01 * mat.a12 - mat.a02 * mat.a11) * invdet,

      (mat.a12 * mat.a20 - mat.a10 * mat.a22) * invdet,
      (mat.a00 * mat.a22 - mat.a02 * mat.a20) * invdet,
      (mat.a10 * mat.a02 - mat.a00 * mat.a12) * invdet,

      (mat.a10 * mat.a21 - mat.a20 * mat.a11) * invdet,
      (mat.a20 * mat.a01 - mat.a00 * mat.a21) * invdet,
      (mat.a00 * mat.a11 - mat.a10 * mat.a01) * invdet);
  }

  template <typename T>
  inline Matrix3<T> transpose(const Matrix3<T>& mat)
  {
    return Matrix3<T>(
      mat.a00, mat.a10, mat.a20, 
      mat.a01, mat.a11, mat.a21, 
      mat.a02, mat.a12, mat.a22);
  }

  // Operator overloads for MatrixX types
  template <typename T, typename U>
  inline Matrix2<T> operator* (Matrix2<T> mat, U f) {
    mat *= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix2<T> operator* (U f, const Matrix2<T>& mat) {
    return mat * f;
  }
  template <typename T, typename U>
  inline Matrix2<T> operator/ (Matrix2<T> mat, U f) {
    mat /= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix2<T> operator/ (U f, const Matrix2<T>& mat) {
    return Matrix2<T>(
      f / mat.a00, f / mat.a01,
      f / mat.a10, f / mat.a11);
  }
  template <typename T, typename U>
  inline Matrix2<T> operator+ (Matrix2<T> mat, U f) {
    mat += f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix2<T> operator+ (U f, const Matrix2<T>& mat) {
    return mat + f;
  }
  template <typename T, typename U>
  inline Matrix2<T> operator- (Matrix2<T> mat, U f) {
    mat -= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix2<T> operator- (U f, const Matrix2<T>& mat) {
    return Matrix2<T>(
      f - mat.a00, f - mat.a01,
      f - mat.a10, f - mat.a11);
  }

  template <typename T>
  inline Matrix2<T> operator* (const Matrix2<T>& mat1, const Matrix2<T>& mat2) {
    return Matrix2<T>(
      mat1.a00*mat2.a00 + mat1.a01*mat2.a10,
      mat1.a00*mat2.a01 + mat1.a01*mat2.a11,

      mat1.a10*mat2.a00 + mat1.a11*mat2.a10,
      mat1.a10*mat2.a01 + mat1.a11*mat2.a11);
  }
  template <typename T>
  inline Matrix2<T> operator+ (const Matrix2<T>& mat1, const Matrix2<T>& mat2) {
    return Matrix2<T>(
      mat1.a00 + mat2.a00, mat1.a01 + mat2.a01,
      mat1.a10 + mat2.a10, mat1.a11 + mat2.a11);
  }
  template <typename T>
  inline Matrix2<T> operator- (const Matrix2<T>& mat1, const Matrix2<T>& mat2) {
    return Matrix2<T>(
      mat1.a00 - mat2.a00, mat1.a01 - mat2.a01,
      mat1.a10 - mat2.a10, mat1.a11 - mat2.a11);
  }

  template <typename T, typename U>
  inline Matrix3<T> operator* (Matrix3<T> mat, U f) {
    mat *= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3<T> operator* (U f, const Matrix3<T>& mat) {
    return mat * f;
  }
  template <typename T, typename U>
  inline Matrix3<T> operator/ (Matrix3<T> mat, U f) {
    mat /= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3<T> operator/ (U f, const Matrix3<T>& mat) {
    return Matrix3<T>(
      f / mat.a00, f / mat.a01, f / mat.a02,
      f / mat.a10, f / mat.a11, f / mat.a12,
      f / mat.a20, f / mat.a21, f / mat.a22);
  }
  template <typename T, typename U>
  inline Matrix3<T> operator+ (Matrix3<T> mat, U f) {
    mat += f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3<T> operator+ (U f, const Matrix3<T>& mat) {
    return mat + f;
  }
  template <typename T, typename U>
  inline Matrix3<T> operator- (Matrix3<T> mat, U f) {
    mat -= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3<T> operator- (U f, const Matrix3<T>& mat) {
    return Matrix3<T>(
      f - mat.a00, f - mat.a01, f - mat.a02,
      f - mat.a10, f - mat.a11, f - mat.a12,
      f - mat.a20, f - mat.a21, f - mat.a22);
  }

  template <typename T>
  inline Matrix3<T> operator* (const Matrix3<T>& mat1, const Matrix3<T>& mat2) {
    return Matrix3<T>(
      mat1.a00*mat2.a00 + mat1.a01*mat2.a10 + mat1.a02*mat2.a20,
      mat1.a00*mat2.a01 + mat1.a01*mat2.a11 + mat1.a02*mat2.a21,
      mat1.a00*mat2.a02 + mat1.a01*mat2.a12 + mat1.a02*mat2.a22,

      mat1.a10*mat2.a00 + mat1.a11*mat2.a10 + mat1.a12*mat2.a20,
      mat1.a10*mat2.a01 + mat1.a11*mat2.a11 + mat1.a12*mat2.a21,
      mat1.a10*mat2.a02 + mat1.a11*mat2.a12 + mat1.a12*mat2.a22,

      mat1.a20*mat2.a00 + mat1.a21*mat2.a10 + mat1.a22*mat2.a20,
      mat1.a20*mat2.a01 + mat1.a21*mat2.a11 + mat1.a22*mat2.a21,
      mat1.a20*mat2.a02 + mat1.a21*mat2.a12 + mat1.a22*mat2.a22);
  }
  template <typename T>
  inline Matrix3<T> operator+ (const Matrix3<T>& mat1, const Matrix3<T>& mat2) {
    return Matrix3<T>(
      mat1.a00 + mat2.a00, mat1.a01 + mat2.a01, mat1.a02 + mat2.a02,
      mat1.a10 + mat2.a10, mat1.a11 + mat2.a11, mat1.a12 + mat2.a12,
      mat1.a20 + mat2.a20, mat1.a21 + mat2.a21, mat1.a22 + mat2.a22);
  }
  template <typename T>
  inline Matrix3<T> operator- (const Matrix3<T>& mat1, const Matrix3<T>& mat2) {
    return Matrix3<T>(
      mat1.a00 - mat2.a00, mat1.a01 - mat2.a01, mat1.a02 - mat2.a02,
      mat1.a10 - mat2.a10, mat1.a11 - mat2.a11, mat1.a12 - mat2.a12,
      mat1.a20 - mat2.a20, mat1.a21 - mat2.a21, mat1.a22 - mat2.a22);
  }

  template <typename T, typename U>
  inline Matrix3x4<T> operator* (Matrix3x4<T> mat, U f) {
    mat *= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3x4<T> operator* (U f, const Matrix3x4<T>& mat) {
    return mat * f;
  }
  template <typename T, typename U>
  inline Matrix3x4<T> operator/ (Matrix3x4<T> mat, U f) {
    mat /= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3x4<T> operator/ (U f, const Matrix3x4<T>& mat) {
    return Matrix3x4<T>(
      f / mat.a00, f / mat.a01, f / mat.a02, f / mat.a03,
      f / mat.a10, f / mat.a11, f / mat.a12, f / mat.a13,
      f / mat.a20, f / mat.a21, f / mat.a22, f / mat.a23);
  }
  template <typename T, typename U>
  inline Matrix3x4<T> operator+ (Matrix3x4<T> mat, U f) {
    mat += f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3x4<T> operator+ (U f, const Matrix3x4<T>& mat) {
    return mat + f;
  }
  template <typename T, typename U>
  inline Matrix3x4<T> operator- (Matrix3x4<T> mat, U f) {
    mat -= f;
    return mat;
  }
  template <typename T, typename U>
  inline Matrix3x4<T> operator- (U f, const Matrix3x4<T>& mat) {
    return Matrix3x4<T>(
      f - mat.a00, f - mat.a01, f - mat.a02, f - mat.a03,
      f - mat.a10, f - mat.a11, f - mat.a12, f - mat.a13,
      f - mat.a20, f - mat.a21, f - mat.a22, f - mat.a23);
  }

  template <typename T>
  inline Matrix3x4<T> operator* (const Matrix3<T>& mat1, const Matrix3x4<T>& mat2) {
    return Matrix3x4<T>(
      mat1.a00*mat2.a00 + mat1.a01*mat2.a10 + mat1.a02*mat2.a20,
      mat1.a00*mat2.a01 + mat1.a01*mat2.a11 + mat1.a02*mat2.a21,
      mat1.a00*mat2.a02 + mat1.a01*mat2.a12 + mat1.a02*mat2.a22,
      mat1.a00*mat2.a03 + mat1.a01*mat2.a13 + mat1.a02*mat2.a23,

      mat1.a10*mat2.a00 + mat1.a11*mat2.a10 + mat1.a12*mat2.a20,
      mat1.a10*mat2.a01 + mat1.a11*mat2.a11 + mat1.a12*mat2.a21,
      mat1.a10*mat2.a02 + mat1.a11*mat2.a12 + mat1.a12*mat2.a22,
      mat1.a10*mat2.a03 + mat1.a11*mat2.a13 + mat1.a12*mat2.a23,

      mat1.a20*mat2.a00 + mat1.a21*mat2.a10 + mat1.a22*mat2.a20,
      mat1.a20*mat2.a01 + mat1.a21*mat2.a11 + mat1.a22*mat2.a21,
      mat1.a20*mat2.a02 + mat1.a21*mat2.a12 + mat1.a22*mat2.a22,
      mat1.a20*mat2.a03 + mat1.a21*mat2.a13 + mat1.a22*mat2.a23);
  }
  template <typename T>
  inline Matrix3x4<T> operator+ (const Matrix3x4<T>& mat1, const Matrix3x4<T>& mat2) {
    return Matrix3x4<T>(
      mat1.a00 + mat2.a00, mat1.a01 + mat2.a01, mat1.a02 + mat2.a02, mat1.a03 + mat2.a03,
      mat1.a10 + mat2.a10, mat1.a11 + mat2.a11, mat1.a12 + mat2.a12, mat1.a13 + mat2.a13,
      mat1.a20 + mat2.a20, mat1.a21 + mat2.a21, mat1.a22 + mat2.a22, mat1.a23 + mat2.a23);
  }
  template <typename T>
  inline Matrix3x4<T> operator- (const Matrix3x4<T>& mat1, const Matrix3x4<T>& mat2) {
    return Matrix3x4<T>(
      mat1.a00 - mat2.a00, mat1.a01 - mat2.a01, mat1.a02 - mat2.a02, mat1.a03 - mat2.a03,
      mat1.a10 - mat2.a10, mat1.a11 - mat2.a11, mat1.a12 - mat2.a12, mat1.a13 - mat2.a13,
      mat1.a20 - mat2.a20, mat1.a21 - mat2.a21, mat1.a22 - mat2.a22, mat1.a23 - mat2.a23);
  }

  // Operator overloads for MatrixX and Vector
  template <typename T>
  inline Vector3<T> operator* (const Matrix3<T>& mat, const Vector2<T>& vec) {
    // Allow this, assume last element of the required 3D vector is 1
    return Vector3<T>(
      mat.a00*vec.x + mat.a01*vec.y + mat.a02,
      mat.a10*vec.x + mat.a11*vec.y + mat.a12,
      mat.a20*vec.x + mat.a21*vec.y + mat.a22);
  }

  template <typename T>
  inline Vector3<T> operator* (const Matrix3<T>& mat, const Vector3<T>& vec) {
    return Vector3<T>(
      mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z,
      mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z,
      mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z);
  }
  template <typename T>
  inline Vector3<T> operator* (const Matrix3x4<T>& mat, const Vector3<T>& vec) {
    // Allow this, assume last element of the required 4D vector is 1
    return Vector3<T>(
      mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03,
      mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13,
      mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23);
  }
  template <typename T>
  inline Vector3<T> operator* (const Matrix3x4<T>& mat, const Vector4<T>& vec) {
    return Vector3<T>(
      mat.a00*vec.x + mat.a01*vec.y + mat.a02*vec.z + mat.a03*vec.w,
      mat.a10*vec.x + mat.a11*vec.y + mat.a12*vec.z + mat.a13*vec.w,
      mat.a20*vec.x + mat.a21*vec.y + mat.a22*vec.z + mat.a23*vec.w);
  }
}