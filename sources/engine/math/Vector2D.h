#ifndef ENGINE_MATH_VECTOR2D_H
#define ENGINE_MATH_VECTOR2D_H

#include <cstddef>

namespace Engine::Math
{
  template<typename T>
  struct Vector2D {
      T x;
      T y;

      Vector2D(const T& x, const T& y): x(x), y(y) {}
  };

  using Vector = Vector2D<double>;
  using Size = Vector2D<size_t>;
}

#endif // ENGINE_MATH_VECTOR2D_H
