#include "Vec2.hpp"

/* Simple float clamp helper function */
float clamp1(float val, float min, float max)
{
	return (val < min ? min : (val > max ? max : val));
}

/* Implementation for the Vec2 constructor */
Vec2::Vec2(float x, float y)
{
	/* Store the x, and y values */
	this->x = x;
	this->y = y;
}

/* Implementation for Vec2.Length */
float Vec2::Length() const 
{ 
	return sqrt(x * x + y * y); 
}

/* Implementation for Vec2.LengthSquared */
float Vec2::LengthSquared() const 
{ 
	return x * x + y * y; 
}

/* Implementation for Vec2.Distance */
float Vec2::Distance(const Vec2& v) const 
{ 
	return sqrt(((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y))); 
}

/* Implementation for Vec2.DistanceSquared */
float Vec2::DistanceSquared(const Vec2& v) const 
{
	return ((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y)); 
}

/* Implementation for Vec2.Dot */
float Vec2::Dot(const Vec2& v) const 
{ 
	return x * v.x + y * v.y; 
}

/* Implementation for Vec2.Cross */
float Vec2::Cross(const Vec2& v) const 
{ 
	return x * v.y + y * v.x; 
}

/* Implementation for Vec2.Normalized */
Vec2 Vec2::Normalized() const
{
	/* Get the magnitude of this vector */
	float mag = this->Length();

	/* Normalize this vector */
	if (mag > 9.99999974737875E-06)
		return *this / mag;
	else
		return Vec2();
}

/* Implementation for Vec2.ToString */
std::string Vec2::ToString() const
{
	/* Convert to a printable string */
	return "Vec2(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}

/* Implementation for Vec2.Angle */
float Vec2::Angle(Vec2 to) const
{
	return acos(clamp1(this->Normalized().Dot(to.Normalized()), -1.0f, 1.0f));
}