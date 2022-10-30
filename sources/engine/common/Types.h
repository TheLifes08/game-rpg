#ifndef ENGINE_MATH_TYPES_H
#define ENGINE_MATH_TYPES_H

#include <SFML/Graphics.hpp>

namespace Engine::Common
{
  using Size = sf::Vector2u;
  using Vector = sf::Vector2f;
  using Position = Vector;
  using Rotation = float;
  using Scale = Vector;
  using Transform = sf::Transform;
}

#endif // ENGINE_MATH_TYPES_H
