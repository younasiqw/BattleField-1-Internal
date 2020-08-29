#ifndef _VEC4_HPP
#define _VEC4_HPP

/* Includes for this header. */
#include <cmath>
#include <string>

/**
 * Vec4 - A class used for Vec3 mathematics, with an x, y, and z axis.
 */
class Vec4
{
public: // Public methods

	/**
	 * The constructor for the Vec4 class.
	 *
	 * @param [in] x The x-axis value.
	 * @param [in] y The y-axis value.
	 */
	Vec4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);

	/* Deconstructor */
	~Vec4() {}

	/**
	 * Used to get the euclidean length of a Vec3.
	 */
	float Length() const;

	/**
	 * Used to get the squared euclidean length of a Vec3.
	 */
	float LengthSquared() const;

	/**
	 * Used to get the 4D distance between this vector and another.
	 *
	 * @param [in] v The vector you want to calculate distance to.
	 * \return float The 4D distance between this vector and v.
	 */
	float Distance(const Vec4& v) const;

	/**
	 * Used to get the 4D distance between this vector and another.
	 *
	 * @param [in] v The vector you want to calculate distance to.
	 * \return float The 4D distance between this vector and v.
	 */
	float DistanceSquared(const Vec4& v) const;

	/**
	 * Used to calculate the dot product between two vectors
	 *
	 * @param [in] v The vector you want to calculate the dot product for
	 * \return float The dot product of the two vectors.
	 */
	float Dot(const Vec4& v) const;

	/**
	 * Used to calculate the cross product between two vectors
	 *
	 * @param [in] v The vector you want to calculate cross product for.
	 * \return float The cross product of the two vectors.
	 */
	float Cross(const Vec4& v) const;

	/**
	 * Used to normalize a Vec3.
	 */
	Vec4 Normalized() const;

	/**
	 * Used to convert the Vec4 to a string.
	 */
	std::string ToString() const;

	/**
	 * Returns the angle in degrees between this and to.
	 */
	float Angle(Vec4 to) const;

public:

	/* Class operations */

	// ASSINGMENT AND EQUALITY OPERATIONS
	inline Vec4& operator = (const Vec4& v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
	inline Vec4& operator = (const float& f) { x = f; y = f; z = f; w = f; return *this; }
	inline Vec4& operator - (void) { x = -x; y = -y; z = -z; w = -w; return *this; }
	inline bool operator == (const Vec4& v) const { return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w); }
	inline bool operator != (const Vec4& v) const { return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w); }

	// Vec4 TO Vec4 OPERATIONS
	inline const Vec4 operator + (const Vec4& v) const { return Vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
	inline const Vec4 operator - (const Vec4& v) const { return Vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
	inline const Vec4 operator * (const Vec4& v) const { return Vec4(x * v.x, y * v.y, z * v.z, w * v.w); }
	inline const Vec4 operator / (const Vec4& v) const { return Vec4(x / v.x, y / v.y, z / v.z, w / v.w); }

	// Vec4 TO THIS OPERATIONS
	inline Vec4& operator += (const Vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
	inline Vec4& operator -= (const Vec4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }
	inline Vec4& operator *= (const Vec4& v) { x *= v.x; y *= v.y; z *= v.z; w *= v.w; return *this; }
	inline Vec4& operator /= (const Vec4& v) { x /= v.x; y /= v.y; z /= v.z; w /= v.w; return *this; }

	// SCALER TO Vec4 OPERATIONS
	inline const Vec4 operator + (float v) const { return Vec4(x + v, y + v, z + v, w + v); }
	inline const Vec4 operator - (float v) const { return Vec4(x - v, y - v, z - v, w - v); }
	inline const Vec4 operator * (float v) const { return Vec4(x * v, y * v, z * v, w * v); }
	inline const Vec4 operator / (float v) const { return Vec4(x / v, y / v, z / v, w / v); }

	// SCALER TO THIS OPERATIONS
	inline Vec4& operator += (float v) { x += v; y += v; z += v; return *this; }
	inline Vec4& operator -= (float v) { x -= v; y -= v; z -= v; return *this; }
	inline Vec4& operator *= (float v) { x *= v; y *= v; y *= v; return *this; }
	inline Vec4& operator /= (float v) { x /= v; y /= v; y /= v; return *this; }

public: // Public fields

	float x; // The x-axis value.
	float y; // The y-axis value.
	float z; // The z-axis value.
	float w; // The w-axis value.
};

#endif // _VEC4_HPP