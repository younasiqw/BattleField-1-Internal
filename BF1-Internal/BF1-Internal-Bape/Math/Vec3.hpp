#ifndef _VEC3_HPP
#define _VEC3_HPP

/* Includes for this header. */
#include <cmath>
#include <string>

/**
 * Vec3 - A class used for Vec4 mathematics, with an x, y, and z axis.
 */
class Vec3
{
public: // Public methods

	/**
	 * The constructor for the Vec3 class.
	 *
	 * @param [in] x The x-axis value.
	 * @param [in] y The y-axis value.
	 */
	Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

	/* Deconstructor */
	~Vec3() {}

	/**
	 * Used to get the euclidean length of a Vec4.
	 */
	float Length() const;

	/**
	 * Used to get the squared euclidean length of a Vec4.
	 */
	float LengthSquared() const;

	/**
	 * Used to get the 3D distance between this vector and another.
	 *
	 * @param [in] v The vector you want to calculate distance to.
	 * \return float The 3D distance between this vector and v.
	 */
	float Distance(const Vec3& v) const;

	/**
	 * Used to get the 3D distance between this vector and another.
	 *
	 * @param [in] v The vector you want to calculate distance to.
	 * \return float The 3D distance between this vector and v.
	 */
	float DistanceSquared(const Vec3& v) const;

	/**
	 * Used to calculate the dot product between two vectors
	 *
	 * @param [in] v The vector you want to calculate the dot product for
	 * \return float The dot product of the two vectors.
	 */
	float Dot(const Vec3& v) const;

	/**
	 * Used to calculate the cross product between two vectors
	 *
	 * @param [in] v The vector you want to calculate cross product for.
	 * \return float The cross product of the two vectors.
	 */
	float Cross(const Vec3& v) const;

	/**
	 * Used to normalize a Vec4.
	 */
	Vec3 Normalized() const;

	/**
	 * Used to convert the Vec4 to a string.
	 */
	std::string ToString() const;

	/**
	 * Returns the angle in degrees between this and to.
	 */
	float Angle(Vec3 to) const;

public:

	/* Class operations */

	// ASSINGMENT AND EQUALITY OPERATIONS
	inline Vec3& operator = (const Vec3& v) { x = v.x; y = v.y; z=v.z; return *this; }
	inline Vec3& operator = (const float& f) { x = f; y = f; z = f; return *this; }
	inline Vec3& operator - (void) { x = -x; y = -y; z = -z; return *this; }
	inline bool operator == (const Vec3& v) const { return (x == v.x) && (y == v.y) && (z == v.z); }
	inline bool operator != (const Vec3& v) const { return (x != v.x) || (y != v.y) || (z != v.z); }

	// Vec4 TO Vec4 OPERATIONS
	inline const Vec3 operator + (const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
	inline const Vec3 operator - (const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
	inline const Vec3 operator * (const Vec3& v) const { return Vec3(x * v.x, y * v.y, z * v.z); }
	inline const Vec3 operator / (const Vec3& v) const { return Vec3(x / v.x, y / v.y, z / v.z); }

	// Vec4 TO THIS OPERATIONS
	inline Vec3& operator += (const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
	inline Vec3& operator -= (const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	inline Vec3& operator *= (const Vec3& v) { x *= v.x; y *= v.y; z *= v.z; return *this; }
	inline Vec3& operator /= (const Vec3& v) { x /= v.x; y /= v.y; z /= v.z; return *this; }

	// SCALER TO Vec4 OPERATIONS
	inline const Vec3 operator + (float v) const { return Vec3(x + v, y + v, z + v); }
	inline const Vec3 operator - (float v) const { return Vec3(x - v, y - v, z - v); }
	inline const Vec3 operator * (float v) const { return Vec3(x * v, y * v, z * v); }
	inline const Vec3 operator / (float v) const { return Vec3(x / v, y / v, z / v); }

	// SCALER TO THIS OPERATIONS
	inline Vec3& operator += (float v) { x += v; y += v; z += v; return *this; }
	inline Vec3& operator -= (float v) { x -= v; y -= v; z -= v; return *this; }
	inline Vec3& operator *= (float v) { x *= v; y *= v; y *= v; return *this; }
	inline Vec3& operator /= (float v) { x /= v; y /= v; y /= v; return *this; }

public: // Public fields

	float x; // The x-axis value.
	float y; // The y-axis value.
	float z; // The z-axis value.
};


/* Used to calculate the dot product of a Vec4 */
float Vec3Dot(const Vec3* pV1, const Vec3* pV2);

#endif // _VEC3_HPP