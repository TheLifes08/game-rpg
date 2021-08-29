#ifndef ENGINE_COMMON_POSITION_H
#define ENGINE_COMMON_POSITION_H

#include <cstddef>


namespace Engine {
    namespace Common {
        template<typename T>
        struct Vector2D {
            T x;
            T y;

            Vector2D(const T& x, const T& y): x(x), y(y) {}
        };

        using Position = Vector2D<double>;
        using Velocity = Vector2D<double>;
        using Size = Vector2D<size_t>;
    }
}


#endif // ENGINE_COMMON_POSITION_H
