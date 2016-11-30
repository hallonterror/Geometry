#pragma once

#include "Vector.h"

namespace dry
{
  template <typename T>
  inline Vector2<T> normalized(const Vector2<T>& vec)
  {
    T denominator = vec.norm();
    return Vector2<T>(vec.x / denominator, vec.y / denominator);
  }
  template <typename T>
  inline Vector3<T> normalized(const Vector3<T>& vec)
  {
    T denominator = vec.norm();
    return Vector3<T>(vec.x / denominator, vec.y / denominator, vec.z / denominator);
  }
  template <typename T>
  inline Vector4<T> normalized(const Vector4<T>& vec)
  {
    T denominator = vec.norm();
    return Vector4<T>(vec.x / denominator, vec.y / denominator, vec.z / denominator, vec.w / denominator);
  }

  template <typename T>
  inline void normalize(Vector2<T>& vec)
  {
    T denominator = vec.norm();
    vec.x = vec.x / denominator;
    vec.y = vec.y / denominator;
  }
  template <typename T>
  inline void normalize(Vector3<T>& vec)
  {
    T denominator = vec.norm();
    vec.x = vec.x / denominator;
    vec.y = vec.y / denominator;
    vec.z = vec.z / denominator;
  }
  template <typename T>
  inline void normalize(Vector4<T>& vec)
  {
    T denominator = vec.norm();
    vec.x = vec.x / denominator;
    vec.y = vec.y / denominator;
    vec.z = vec.z / denominator;
    vec.w = vec.w / denominator;
  }

  template <typename T>
  inline T dot(const Vector2<T>& first, const Vector2<T>& second)
  {
    return first.x*second.x + first.y*second.y;
  }
  template <typename T>
  inline T dot(const Vector3<T>& first, const Vector3<T>& second)
  {
    return first.x*second.x + first.y*second.y + first.z*second.z;
  }
  template <typename T>
  inline T dot(const Vector4<T>& first, const Vector4<T>& second)
  {
    return first.x*second.x + first.y*second.y + first.z*second.z + first.w*second.w;
  }

  template <typename T>
  inline Vector3<T> cross(const Vector3<T>& first, const Vector3<T>& second)
  {
    return Vector3<T>(
      first.y*second.z - first.z*second.y,
      first.z*second.x - first.x*second.z, 
      first.x*second.y - first.y*second.x);
  }

  template <typename T>
  inline Vector2<T> toInhomogeneous(const Vector3<T>& vec)
  {
    return Vector2<T>(vec.x / vec.z, vec.y / vec.z);
  }
  template <typename T>
  inline Vector3<T> toInhomogeneous(const Vector4<T>& vec)
  {
    return Vector3<T>(vec.x / vec.w, vec.y / vec.w, vec.z / vec.w);
  }
  template <typename T>
  inline Vector3<T> toHomogeneous(const Vector2<T>& vec)
  {
    return Vector3<T>(vec.x, vec.y, T(1));
  }
  template <typename T>
  inline Vector4<T> toHomogeneous(const Vector3<T>& vec)
  {
    return Vector4<T>(vec.x, vec.y, vec.z, T(1.0));
  }

  template <typename T, typename U>
  inline Vector2<T> operator* (Vector2<T> vec, U f) {
    vec *= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector2<T> operator* (U f, const Vector2<T>& vec) {
    return vec * f;
  }
  template <typename T, typename U>
  inline Vector2<T> operator/ (Vector2<T> vec, U f) {
    vec /= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector2<T> operator/ (U f, const Vector2<T>& vec) {
    return Vector3<T>(f / vec.x, f / vec.y);
  }
  template <typename T, typename U>
  inline Vector2<T> operator+ (Vector2<T> vec, U f) {
    vec += f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector2<T> operator+ (U f, const Vector2<T>& vec) {
    return vec + f;
  }
  template <typename T, typename U>
  inline Vector2<T> operator- (Vector2<T> vec, U f) {
    vec -= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector2<T> operator- (U f, const Vector2<T>& vec) {
    return Vector3<T>(f - vec.x, f - vec.y);
  }

  template <typename T, typename U>
  inline Vector2<T> operator* (const Vector2<T>& vec1, const Vector2<U>& vec2) {
    return Vector2<T>(vec1.x*vec2.x, vec1.y*vec2.y);
  }
  template <typename T, typename U>
  inline Vector2<T> operator/ (const Vector2<T>& vec1, const Vector2<U>& vec2) {
    return Vector2<T>(vec1.x/vec2.x, vec1.y/vec2.y);
  }
  template <typename T, typename U>
  inline Vector2<T> operator+ (const Vector2<T>& vec1, const Vector2<U>& vec2) {
    return Vector2<T>(vec1.x + vec2.x, vec1.y + vec2.y);
  }
  template <typename T, typename U>
  inline Vector2<T> operator- (const Vector2<T>& vec1, const Vector2<U>& vec2) {
    return Vector2<T>(vec1.x - vec2.x, vec1.y - vec2.y);
  }

  template <typename T, typename U>
  inline Vector3<T> operator* (Vector3<T> vec, U f) {
    vec *= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector3<T> operator* (U f, const Vector3<T>& vec) {
    return vec * f;
  }
  template <typename T, typename U>
  inline Vector3<T> operator/ (Vector3<T> vec, U f) {
    vec /= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector3<T> operator/ (U f, const Vector3<T>& vec) {
    return Vector3<T>(f / vec.x, f / vec.y, f / vec.z);
  }
  template <typename T, typename U>
  inline Vector3<T> operator+ (Vector3<T> vec, U f) {
    vec += f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector3<T> operator+ (U f, const Vector3<T>& vec) {
    return vec + f;
  }
  template <typename T, typename U>
  inline Vector3<T> operator- (Vector3<T> vec, U f) {
    vec -= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector3<T> operator- (U f, const Vector3<T>& vec) {
    return Vector3<T>(f - vec.x, f - vec.y, f - vec.z);
  }

  template <typename T, typename U>
  inline Vector3<T> operator* (const Vector3<T>& vec1, const Vector3<U>& vec2) {
    return Vector3<T>(vec1.x*vec2.x, vec1.y*vec2.y, vec1.z*vec2.z);
  }
  template <typename T, typename U>
  inline Vector3<T> operator/ (const Vector3<T>& vec1, const Vector3<U>& vec2) {
    return Vector3<T>(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z);
  }
  template <typename T, typename U>
  inline Vector3<T> operator+ (const Vector3<T>& vec1, const Vector3<U>& vec2) {
    return Vector3<T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
  }
  template <typename T, typename U>
  inline Vector3<T> operator- (const Vector3<T>& vec1, const Vector3<U>& vec2) {
    return Vector3<T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
  }

  template <typename T, typename U>
  inline Vector4<T> operator* (Vector4<T> vec, U f) {
    vec *= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector4<T> operator* (U f, const Vector4<T>& vec) {
    return vec * f;
  }
  template <typename T, typename U>
  inline Vector4<T> operator/ (Vector4<T> vec, U f) {
    vec /= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector4<T> operator/ (U f, const Vector4<T>& vec) {
    return Vector3<T>(f / vec.x, f / vec.y, f / vec.z, f / vec.w);
  }
  template <typename T, typename U>
  inline Vector4<T> operator+ (Vector4<T> vec, U f) {
    vec += f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector4<T> operator+ (U f, const Vector4<T>& vec) {
    return vec + f;
  }
  template <typename T, typename U>
  inline Vector4<T> operator- (Vector4<T> vec, U f) {
    vec -= f;
    return vec;
  }
  template <typename T, typename U>
  inline Vector4<T> operator- (U f, const Vector4<T>& vec) {
    return Vector4<T>(f - vec.x, f - vec.y, f - vec.z, f - vec.w);
  }

  template <typename T, typename U>
  inline Vector4<T> operator* (const Vector4<T>& vec1, const Vector4<U>& vec2) {
    return Vector4<T>(vec1.x*vec2.x, vec1.y*vec2.y, vec1.z*vec2.z, vec1.w*vec2.w);
  }
  template <typename T, typename U>
  inline Vector4<T> operator/ (const Vector4<T>& vec1, const Vector4<U>& vec2) {
    return Vector4<T>(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z, vec1.w / vec2.w);
  }
  template <typename T, typename U>
  inline Vector4<T> operator+ (const Vector4<T>& vec1, const Vector4<U>& vec2) {
    return Vector4<T>(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z, vec1.w + vec2.w);
  }
  template <typename T, typename U>
  inline Vector4<T> operator- (const Vector4<T>& vec1, const Vector4<U>& vec2) {
    return Vector4<T>(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z, vec1.w - vec2.w);
  }

}