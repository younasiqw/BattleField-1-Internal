#include "Vec4.hpp"

/* Simple float clamp helper function */
float clamp3(float val, float min, float max)
{
	return (val < min ? min : (val > max ? max : val));
}

/* Implementation for the Vec4 constructor */
Vec4::Vec4(float x, float y, float z, float w)
{
	/* Store the x, and y values */
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

/* Implementation for Vec4.Length */
float Vec4::Length() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

/* Implementation for Vec4.LengthSquared */
float Vec4::LengthSquared() const
{
	return x * x + y * y + z * z + w * w;
}

/* Implementation for Vec4.Distance */
float Vec4::Distance(const Vec4& v) const
{
	/* Sub the two vectors */
	Vec4 p1 = *this - v;

	/* Calculate the distance */
	return sqrt(p1.x * p1.x + p1.y * p1.y + p1.z * p1.z + p1.w * p1.w);
}

/* Implementation for Vec4.DistanceSquared */
float Vec4::DistanceSquared(const Vec4& v) const
{
	return ((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y)) + ((z - v.z) * (z - v.z)) + ((w - v.w) * (w - v.w));
}

/* Implementation for Vec4.Dot */
float Vec4::Dot(const Vec4& v) const
{
	return x * v.x + y * v.y + z * v.z + w * v.w;
}

/* Implementation for Vec4.Normalized */
Vec4 Vec4::Normalized() const
{
	/* Get the magnitude of this vector */
	float mag = this->Length();

	/* Normalize this vector */
	if (mag > 9.99999974737875E-06)
		return *this / mag;
	else
		return Vec4();
}

/* Implementation for Vec4.ToString */
std::string Vec4::ToString() const
{
	/* Convert to a printable string */
	return "Vec4(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ", " + std::to_string(this->w) + ")";
}

/* Implementation for Vec4.Angle */
float Vec4::Angle(Vec4 to) const
{
	return acos(clamp3(this->Normalized().Dot(to.Normalized()), -1.0f, 1.0f));
}