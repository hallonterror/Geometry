#pragma once
#include "Types.h"
namespace dry
{
  //!\brief General data container
  template <typename T, size_t N, size_t M>
  class Matrix
  {
  public:
    Matrix() {}

    T& operator()(size_t x, size_t y) { return v[y*N + x]; }
    const T& operator()(size_t x, size_t y) const { return v[y*N + x]; }

    T& operator[](size_t idx) { return v[idx]; }
    const T& operator[](size_t idx) const { return v[idx]; }

    T v[N*M];

    static Matrix Identity() { 
      Matrix m;
      std::memset(&m, 0, sizeof(T)*N*M);
      for (size_t i = 0; i < std::min(N, M); ++i)
        m(i, i) = T(1);
      return m;
    }
  };

  //!\brief Fix size container
  template <typename T>
  class Matrix2
  {
  public:
    Matrix2() : a00(0), a01(0), a10(0), a11(0) {}
    Matrix2(const T& a00, const T& a01, const T& a10, const T& a11)
      : a00(a00), a01(a01)
      , a10(a10), a11(a11) {}

    T a00;  T a01;
    T a10;  T a11;

    static Matrix2 Identity() { return Matrix2(T(1), T(0), T(0), T(1)); }
  };
  template <typename T>
  class Matrix3
  {
  public:
    Matrix3() : a00(0), a01(0), a10(0), a11(0) {}
    Matrix3(const T& a00, const T& a01, const T& a02,
      const T& a10, const T& a11, const T& a12,
      const T& a20, const T& a21, const T& a22)
      : a00(a00), a01(a01), a02(a02)
      , a10(a10), a11(a11), a12(a12)
      , a20(a20), a21(a21), a22(a22) {}

    T a00;  T a01;  T a02;
    T a10;  T a11;  T a12;
    T a20;  T a21;  T a22;

    static Matrix3 Identity() { return Matrix3(T(1), T(0), T(0), T(0), T(1), T(0), T(0), T(0), T(1)); }
  };
  template <typename T>
  class Matrix3x4
  {
  public:
    Matrix3x4() : a00(0), a01(0), a10(0), a11(0) {}
    Matrix3x4(const T& a00, const T& a01, const T& a02, const T& a03,
      const T& a10, const T& a11, const T& a12, const T& a13,
      const T& a20, const T& a21, const T& a22, const T& a23)
      : a00(a00), a01(a01), a02(a02), a03(a03)
      , a10(a10), a11(a11), a12(a12), a13(a13)
      , a20(a20), a21(a21), a22(a22), a23(a23) {}

    T a00;  T a01;  T a02;  T a03;
    T a10;  T a11;  T a12;  T a13;
    T a20;  T a21;  T a22;  T a23;

    static Matrix3x4 Identity() { return Matrix3x4(T(1), T(0), T(0), T(0), T(0), T(1), T(0), T(0), T(0), T(0), T(1), T(0)); }
  };

  typedef Matrix2<float32> Matrix2f;
  typedef Matrix3<float32> Matrix3f;
  typedef Matrix3x4<float32> Matrix3x4f;

  typedef Matrix2<float64> Matrix2d;
  typedef Matrix3<float64> Matrix3d;
  typedef Matrix3x4<float64> Matrix3x4d;
}