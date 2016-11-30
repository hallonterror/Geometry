#pragma once

#include "Types.h"

namespace dry
{
  template <typename T>
  class Vector2
  {
  public:
    Vector2() {};
    Vector2(const T& x, const T& y) : x(x), y(y) {}

    T x;
    T y;

    T& operator[](size_t idx) { return *(&x+idx); }
    const T& operator[](size_t idx) const { return *(&x + idx); }

    template <typename U>
    Vector2 operator*=(U f)
    {
      x *= f;
      y *= f;
      return *this;
    }
    template <typename U>
    Vector2 operator/=(U f)
    {
      x /= f;
      y /= f;
      return *this;
    }
    template <typename U>
    Vector2 operator+=(U f)
    {
      x += f;
      y += f;
      return *this;
    }
    template <typename U>
    Vector2 operator-=(U f)
    {
      x -= f;
      y -= f;
      return *this;
    }

    T norm() { return std::sqrt(vec.x*vec.x + vec.y*vec.y); }
    T norm2() { return vec.x*vec.x + vec.y*vec.y; }
  };

  template <typename T>
  class Vector3
  {
  public:
    Vector3() {};
    Vector3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}

    T x;
    T y;
    T z;

    T& operator[](size_t idx) { return *(&x + idx); }
    const T& operator[](size_t idx) const { return *(&x + idx); }

    template <typename U>
    Vector3 operator*=(U f)
    {
      x *= f;
      y *= f;
      z *= f;
      return *this;
    }
    template <typename U>
    Vector3 operator/=(U f)
    {
      x /= f;
      y /= f;
      z /= f;
      return *this;
    }
    template <typename U>
    Vector3 operator+=(U f)
    {
      x += f;
      y += f;
      z += f;
      return *this;
    }
    template <typename U>
    Vector3 operator-=(U f)
    {
      x -= f;
      y -= f;
      z -= f;
      return *this;
    }

    T norm() { return std::sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z); }
    T norm2() { return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z; }
  };

  template <typename T>
  class Vector4
  {
  public:
    Vector4() {};
    Vector4(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}

    T x;
    T y;
    T z;
    T w;

    T& operator[](size_t idx) { return *(&x + idx); }
    const T& operator[](size_t idx) const { return *(&x + idx); }

    template <typename U>
    Vector4 operator*=(U f)
    {
      x *= f;
      y *= f;
      z *= f;
      w *= f;
      return *this;
    }
    template <typename U>
    Vector4 operator/=(U f)
    {
      x /= f;
      y /= f;
      z /= f;
      w *= f;
      return *this;
    }
    template <typename U>
    Vector4 operator+=(U f)
    {
      x += f;
      y += f;
      z += f;
      w *= f;
      return *this;
    }
    template <typename U>
    Vector4 operator-=(U f)
    {
      x -= f;
      y -= f;
      z -= f;
      w *= f;
      return *this;
    }

    T norm() { return std::sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w); }
    T norm2() { return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w; }
  };

  typedef Vector2<float32> Vector2f;
  typedef Vector3<float32> Vector3f;
  typedef Vector4<float32> Vector4f;

  typedef Vector2<float64> Vector2d;
  typedef Vector3<float64> Vector3d;
  typedef Vector4<float64> Vector4d;
}