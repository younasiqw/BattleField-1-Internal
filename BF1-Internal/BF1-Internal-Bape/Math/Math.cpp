#include "Math.hpp"

/* Implementation for clamp */
float clamp(float val, float min, float max)
{
	return (val > max ? max : (val < min ? min : val));
}