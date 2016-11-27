#pragma once

#include "Vec.h"

namespace dry
{

  template <typename T>
  class Point2 : public Vec2<T>
  {
  public:
    Point2() {}
    Point2(const T& x, const T& y) : Vec2<T>(x, y) {}
  };

  template <typename T>
  class Point3 : public Vec3<T>
  {
  public:
    Point3() {}
    Point3(const T& x, const T& y, const T& z) : Vec3<T>(x,y,z) {}
  };

  typedef Point2<int32> Point2i;
  typedef Point3<int32> Point3i;

  typedef Point2<float32> Point2f;
  typedef Point3<float32> Point3f;

  typedef Point2<float64> Point2d;
  typedef Point3<float64> Point3d;

}