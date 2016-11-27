#pragma once

#include "Types.h"

namespace dry
{
  template <typename T>
  class Vec2
  {
  public:
    Vec2() {};
    Vec2(const T& x, const T& y) : x(x), y(y) {}

    T x;
    T y;

    T& operator[](size_t idx) { return *(&x+idx); }
    const T& operator[](size_t idx) const { return *(&x + idx); }
  };

  template <typename T>
  class Vec3
  {
  public:
    Vec3() {};
    Vec3(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {}

    T x;
    T y;
    T z;

    T& operator[](size_t idx) { return *(&x + idx); }
    const T& operator[](size_t idx) const { return *(&x + idx); }
  };

  template <typename T>
  class Vec4
  {
  public:
    Vec4() {};
    Vec4(const T& x, const T& y, const T& z, const T& w) : x(x), y(y), z(z), w(w) {}

    T x;
    T y;
    T z;
    T w;

    T& operator[](size_t idx) { return *(&x + idx); }
    const T& operator[](size_t idx) const { return *(&x + idx); }
  };

  template <typename T>
  Vec2<T> normalized(const Vec2<T>& vec)
  {
    T denominator = std::sqrt(vec.x*vec.x + vec.y*vec.y);
    return Vec2<T>(vec.x / denominator, vec.y / denominator);
  }
  template <typename T>
  Vec3<T> normalized(const Vec3<T>& vec)
  {
    T denominator = std::sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
    return Vec3<T>(vec.x / denominator, vec.y / denominator, vec.z / denominator);
  }
  template <typename T>
  Vec4<T> normalized(const Vec4<T>& vec)
  {
    T denominator = std::sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w);
    return Vec4<T>(vec.x / denominator, vec.y / denominator, vec.z / denominator, vec.w / denominator);
  }

  template <typename T>
  void normalize(Vec2<T>& vec)
  {
    T denominator = std::sqrt(vec.x*vec.x + vec.y*vec.y);
    vec.x = vec.x / denominator;
    vec.y = vec.y / denominator;
  }
  template <typename T>
  void normalize(Vec3<T>& vec)
  {
    T denominator = std::sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
    vec.x = vec.x / denominator;
    vec.y = vec.y / denominator;
    vec.z = vec.z / denominator;
  }
  template <typename T>
  void normalize(Vec4<T>& vec)
  {
    T denominator = std::sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z + vec.w*vec.w);
    vec.x = vec.x / denominator;
    vec.y = vec.y / denominator;
    vec.z = vec.z / denominator;
    vec.w = vec.w / denominator;
  }


  typedef Vec2<float32> Vec2f;
  typedef Vec3<float32> Vec3f;
  typedef Vec4<float32> Vec4f;

  typedef Vec2<float64> Vec2d;
  typedef Vec3<float64> Vec3d;
  typedef Vec4<float64> Vec4d;
}