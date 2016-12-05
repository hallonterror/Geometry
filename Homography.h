#pragma once

#include "MatrixOperations.h"
#include "VectorOperations.h"

#include <vector>
#include <numeric>
#include <algorithm>

namespace dry
{
  class Homography
  {
  public:
    Homography() {};

    void clear() {
      left.clear();
      right.clear();
    }

    template <typename T>
    void addCorrespondence(const Vector2<T>& l, const Vector2<T>& r)
    {
      left.push_back(l);
      right.push_back(r);
    }
    size_t getCorrespondenceCount() const { return left.size(); }

    bool estimate(Matrix3d& H)
    {

    }

  private:
    void getHartleyNormalization(const std::vector<Vector2d>& data, Matrix3d& normalization)
    {
      // Calculate mean
      Vector2d sum = std::accumulate(data.begin(), data.end(), Vector2d(0, 0));
      Vector2d mean = sum / data.size();

      // Calculate standard deviation
      std::vector<Vector2d> diff(data.size());
      std::transform(data.begin(), data.end(), diff.begin(), [mean](const Vector2d& x) { return x - mean; });
      Vector2d sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), Vector2d(0,0));
      Vector2d stdev(std::sqrt(sq_sum.x / data.size()), std::sqrt(sq_sum.y / data.size()));

      // Compose normalization
      normalization = Matrix3d::Identity();
      normalization.a00 = std::sqrt(2) / stdev.x;
      normalization.a11 = std::sqrt(2) / stdev.y;
      normalization.a02 = -mean.x * normalization.a00; // TODO: Check that this is right!
      normalization.a12 = -mean.y * normalization.a11;
    }

    std::vector<Vector2d> left;
    std::vector<Vector2d> right;
  };
}