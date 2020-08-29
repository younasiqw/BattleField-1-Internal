#include "Vec3.hpp"

/* Simple float clamp helper function */
float clamp2(float val, float min, float max)
{
	return (val < min ? min : (val > max ? max : val));
}

/* Implementation for the Vec3 constructor */
Vec3::Vec3(float x, float y, float z)
{
	/* Store the x, and y values */
	this->x = x;
	this->y = y;
	this->z = z;
}

/* Implementation for Vec3.Length */
float Vec3::Length() const
{
	return sqrt(x * x + y * y + z * z);
}

/* Implementation for Vec3.LengthSquared */
float Vec3::LengthSquared() const
{
	return x * x + y * y + z * z;
}

/* Implementation for Vec3.Distance */
float Vec3::Distance(const Vec3& v) const
{
	/* Sub the two vectors */
	Vec3 p1 = *this - v;

	/* Calculate the distance */
	return sqrt(p1.x * p1.x + p1.y * p1.y + p1.z * p1.z);
}

/* Implementation for Vec3.DistanceSquared */
float Vec3::DistanceSquared(const Vec3& v) const
{
	return ((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y)) + ((z - v.z) * (z - v.z));
}

/* Implementation for Vec3.Dot */
float Vec3::Dot(const Vec3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

/* Implementation for Vec3.Normalized */
Vec3 Vec3::Normalized() const
{
	/* Get the magnitude of this vector */
	float mag = this->Length();

	/* Normalize this vector */
	if (mag > 9.99999974737875E-06)
		return *this / mag;
	else
		return Vec3();
}

/* Implementation for Vec3.ToString */
std::string Vec3::ToString() const
{
	/* Convert to a printable string */
	return "Vec3(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")";
}

/* Implementation for Vec3.Angle */
float Vec3::Angle(Vec3 to) const
{
	return acos(clamp2(this->Normalized().Dot(to.Normalized()), -1.0f, 1.0f));
}

/* Implementation for Vec3Dot */
float Vec3Dot(const Vec3* pV1, const Vec3* pV2)
{
	return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
}