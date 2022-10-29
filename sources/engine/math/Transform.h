#ifndef ENGINE_MATH_TRANSFORM_H
#define ENGINE_MATH_TRANSFORM_H

#include <engine/math/Vector2D.h>

namespace Engine::Math
{
  struct Transform
  {
    Vector position;
    double rotation;
    Vector scale;
  };
}

#endif // ENGINE_MATH_TRANSFORM_H
