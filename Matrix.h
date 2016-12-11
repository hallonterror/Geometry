#pragma once
#include "Types.h"
namespace dry
{
  //!\brief General data container
  template <typename T>
  class MatrixX
  {
  public:
    MatrixX(size_t N, size_t M) 
      : rows(N), cols(M), size(N*M)
    {
      v = new T[size];
    }

    template <typename U>
    MatrixX(const MatrixX<U>& other)
      : rows(other.rows), cols(other.cols), size(other.size)
    {
      v = new T[size];
      T* ptr = v;
      T* ptr_end = v + size;
      U* ptr_other = other.v;
      while (ptr != ptr_end)
        *ptr++ *= T(*ptr_other++);
      return *this;
    }

    ~MatrixX()
    {
      delete[] v;
    }

    T& operator()(size_t r, size_t c) { return v[r*N + c]; }
    const T& operator()(size_t r, size_t c) const { return v[r*N + c]; }

    T& operator[](size_t idx) { return v[idx]; }
    const T& operator[](size_t idx) const { return v[idx]; }

    T* v;
    size_t rows;
    size_t cols;
    size_t size;

    template <typename U>
    MatrixX operator*=(U f)
    {
      T* ptr = v;
      T* ptr_end = v + size;
      while (ptr != ptr_end)
        *ptr++ *= f;
      return *this;
    }
    template <typename U>
    MatrixX operator/=(U f)
    {
      T* ptr = v;
      T* ptr_end = v + size;
      while (ptr != ptr_end)
        *ptr++ /= f;
      return *this;
    }
    template <typename U>
    MatrixX operator+=(U f)
    {
      T* ptr = v;
      T* ptr_end = v + size;
      while (ptr != ptr_end)
        *ptr++ += f;
      return *this;
    }
    template <typename U>
    MatrixX operator-=(U f)
    {
      T* ptr = v;
      T* ptr_end = v + size;
      while (ptr != ptr_end)
        *ptr++ -= f;
      return *this;
    }
    template <typename U>
    bool operator==(const MatrixX<U>& other) const
    {
      const T* ptr = v;
      const T* ptr_end = v + size;
      const U* ptr_other = other.v;
      while (ptr != ptr_end)
        if (*ptr++ != *ptr_other++)
          return false;
      return true;
    }
    template <typename U>
    bool operator!=(const MatrixX<U>& other) const
    {
      return !(*this == other);
    }

    static MatrixX Identity() {
      MatrixX m;
      std::memset(&m, 0, sizeof(T)*size);
      for (size_t i = 0; i < std::min(N, M); ++i)
        m(i, i) = T(1);
      return m;
    }
    MatrixX& Set(const T& value)
    {
      std::fill_n(v, size, value);
      return *this;
    }
  };

  //!\brief Fix size containers
  template <typename T>
  class Matrix2
  {
  public:
    Matrix2() : a00(0), a01(0), a10(0), a11(0) {}
    Matrix2(const T& a00, const T& a01, const T& a10, const T& a11)
      : a00(a00), a01(a01)
      , a10(a10), a11(a11) {}

    template <typename U>
    Matrix2(const Matrix2<U>& other)
      : a00(T(other.a00)), a01(T(other.a01)), a10(T(other.a10)), a11(T(other.a11)) {}

    T& operator()(size_t r, size_t c) { return *(&a00 + 2 * r + c); }
    const T& operator()(size_t r, size_t c) const { return *(&a00 + 2 * r + c); }

    T& operator[](size_t idx) { return *(&a00 + idx); }
    const T& operator[](size_t idx) const { return *(&a00 + idx); }

    T a00;  T a01;
    T a10;  T a11;

    template <typename U>
    Matrix2 operator*=(U f)
    {
      a00 *= f; a01 *= f;
      a10 *= f; a11 *= f;
      return *this;
    }
    template <typename U>
    Matrix2 operator/=(U f)
    {
      a00 /= f; a01 /= f;
      a10 /= f; a11 /= f;
      return *this;
    }
    template <typename U>
    Matrix2 operator+=(U f)
    {
      a00 += f; a01 += f;
      a10 += f; a11 += f;
      return *this;
    }
    template <typename U>
    Matrix2 operator-=(U f)
    {
      a00 -= f; a01 -= f;
      a10 -= f; a11 -= f;
      return *this;
    }
    template <typename U>
    bool operator==(const Matrix2<U>& other) const
    {
      return a00 == other.a00 && a01 == other.a01 &&
             a10 == other.a10 && a11 == other.a11;
    }
    template <typename U>
    bool operator!=(const Matrix2<U>& other) const
    {
      return !(*this == other);
    }

    static Matrix2 Identity() { return Matrix2(T(1), T(0), T(0), T(1)); }
    Matrix2& Set(const T& value)
    {
      std::fill_n(&a00, 4, value);
      return *this;
    }
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

    template <typename U>
    Matrix3(const Matrix3<U>& other)
      : a00(T(other.a00)), a01(T(other.a01)), a02(T(other.a02))
      , a10(T(other.a10)), a11(T(other.a11)), a12(T(other.a12))
      , a20(T(other.a20)), a21(T(other.a21)), a22(T(other.a22)) {}

    T& operator()(size_t r, size_t c) { return *(&a00 + 3 * r + c); }
    const T& operator()(size_t r, size_t c) const { return *(&a00 + 3 * r + c); }

    T& operator[](size_t idx) { return *(&a00 + idx); }
    const T& operator[](size_t idx) const { return *(&a00 + idx); }

    T a00;  T a01;  T a02;
    T a10;  T a11;  T a12;
    T a20;  T a21;  T a22;

    template <typename U>
    Matrix3 operator*=(U f)
    {
      a00 *= f; a01 *= f; a02 *= f;
      a10 *= f; a11 *= f; a12 *= f;
      a20 *= f; a21 *= f; a22 *= f;
      return *this;
    }
    template <typename U>
    Matrix3 operator/=(U f)
    {
      a00 /= f; a01 /= f; a02 /= f;
      a10 /= f; a11 /= f; a12 /= f;
      a20 /= f; a21 /= f; a22 /= f;
      return *this;
    }
    template <typename U>
    Matrix3 operator+=(U f)
    {
      a00 += f; a01 += f; a02 += f;
      a10 += f; a11 += f; a12 += f;
      a20 += f; a21 += f; a22 += f;
      return *this;
    }
    template <typename U>
    Matrix3 operator-=(U f)
    {
      a00 -= f; a01 -= f; a02 -= f;
      a10 -= f; a11 -= f; a12 -= f;
      a20 -= f; a21 -= f; a22 -= f;
      return *this;
    }
    template <typename U>
    bool operator==(const Matrix2<U>& other) const
    {
      return a00 == other.a00 && a01 == other.a01 && a02 == other.a02 &&
             a10 == other.a10 && a11 == other.a11 && a12 == other.a12 &&
             a20 == other.a20 && a21 == other.a21 && a22 == other.a22;
    }
    template <typename U>
    bool operator!=(const Matrix3<U>& other) const
    {
      return !(*this == other);
    }

    static Matrix3 Identity() { return Matrix3(T(1), T(0), T(0), T(0), T(1), T(0), T(0), T(0), T(1)); }
    Matrix3& Set(const T& value)
    {
      std::fill_n(&a00, 9, value);
      return *this;
    }
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

    template <typename U>
    Matrix3x4(const Matrix3x4<U>& other)
      : a00(T(other.a00)), a01(T(other.a01)), a02(T(other.a02)), a03(T(other.a03))
      , a10(T(other.a10)), a11(T(other.a11)), a12(T(other.a12)), a13(T(other.a13))
      , a20(T(other.a20)), a21(T(other.a21)), a22(T(other.a22)), a23(T(other.a23)) {}

    T& operator()(size_t r, size_t c) { return *(&a00 + 4 * r + c); }
    const T& operator()(size_t r, size_t c) const { return *(&a00 + 4 * r + c); }

    T& operator[](size_t idx) { return *(&a00 + idx); }
    const T& operator[](size_t idx) const { return *(&a00 + idx); }

    T a00;  T a01;  T a02;  T a03;
    T a10;  T a11;  T a12;  T a13;
    T a20;  T a21;  T a22;  T a23;

    template <typename U>
    Matrix3x4 operator*=(U f)
    {
      a00 *= f; a01 *= f; a02 *= f; a03 *= f;
      a10 *= f; a11 *= f; a12 *= f; a13 *= f;
      a20 *= f; a21 *= f; a22 *= f; a23 *= f;
      return *this;
    }
    template <typename U>
    Matrix3x4 operator/=(U f)
    {
      a00 /= f; a01 /= f; a02 /= f; a03 /= f;
      a10 /= f; a11 /= f; a12 /= f; a13 /= f;
      a20 /= f; a21 /= f; a22 /= f; a23 /= f;
      return *this;
    }
    template <typename U>
    Matrix3x4 operator+=(U f)
    {
      a00 += f; a01 += f; a02 += f; a03 += f;
      a10 += f; a11 += f; a12 += f; a13 += f;
      a20 += f; a21 += f; a22 += f; a23 += f;
      return *this;
    }
    template <typename U>
    Matrix3x4 operator-=(U f)
    {
      a00 -= f; a01 -= f; a02 -= f; a03 -= f;
      a10 -= f; a11 -= f; a12 -= f; a13 -= f;
      a20 -= f; a21 -= f; a22 -= f; a23 -= f;
      return *this;
    }
    template <typename U>
    bool operator==(const Matrix3x4<U>& other) const
    {
      return a00 == other.a00 && a01 == other.a01 && a02 == other.a02 && a03 == other.a03 &&
             a10 == other.a10 && a11 == other.a11 && a12 == other.a12 && a13 == other.a13 &&
             a20 == other.a20 && a21 == other.a21 && a22 == other.a22 && a23 == other.a23;
    }
    template <typename U>
    bool operator!=(const Matrix3x4<U>& other) const
    {
      return !(*this == other);
    }

    static Matrix3x4 Identity() { return Matrix3x4(T(1), T(0), T(0), T(0), T(0), T(1), T(0), T(0), T(0), T(0), T(1), T(0)); }
    Matrix3x4& Set(const T& value)
    {
      std::fill_n(&a00, 12, value);
      return *this;
    }
  };

  typedef MatrixX<float32> MatrixXf;
  typedef Matrix2<float32> Matrix2f;
  typedef Matrix3<float32> Matrix3f;
  typedef Matrix3x4<float32> Matrix3x4f;

  typedef MatrixX<float64> MatrixXd;
  typedef Matrix2<float64> Matrix2d;
  typedef Matrix3<float64> Matrix3d;
  typedef Matrix3x4<float64> Matrix3x4d;
}