#ifndef _GAME_MATH_HPP
#define _GAME_MATH_HPP

/* Includes */
#include "Vec3.hpp"
#include "Vec2.hpp"
#include "Matrix4x4.hpp"
#include <cstdint>


/* Convert Vec3 world position to Vec2 screen position */
Vec2 W2S(Vec3 origin, Matrix4x4* view_Matrix4x4, uint64_t camera);

#endif // _GAME_MATH_HPP