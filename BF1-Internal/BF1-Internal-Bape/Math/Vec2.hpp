#ifndef _VEC2_HPP
#define _VEC2_HPP

/* Includes for this header */
#include <cmath>
#include <string>

/**
 * Vec2 - A class used for Vector2 mathematics, with an x, and y axis.
 */
class Vec2
{
public: // Public methods

	/**
	 * The constructor for the Vec2 class.
	 * 
	 * @param [in] x The x-axis value.
	 * @param [in] y The y-axis value.
	 */
	Vec2(float x = 0.0f, float y = 0.0f);

	/* Deconstructor */
	~Vec2() {}

	/**
	 * Used to get the euclidean length of a Vector2.
	 */
	float Length() const;

	/**
	 * Used to get the squared euclidean length of a Vector2.
	 */
	float LengthSquared() const;

	/**
	 * Used to get the 2D distance between this vector and another.
	 * 
	 * @param [in] v The vector you want to calculate distance to.
	 * \return float The 2D distance between this vector and v.
	 */
	float Distance(const Vec2& v) const;

	/**
	 * Used to get the 2D distance between this vector and another.
	 *
	 * @param [in] v The vector you want to calculate distance to.
	 * \return float The 2D distance between this vector and v.
	 */
	float DistanceSquared(const Vec2& v) const;

	/**
	 * Used to calculate the dot product between two vectors
	 *
	 * @param [in] v The vector you want to calculate the dot product for
	 * \return float The dot product of the two vectors.
	 */
	float Dot(const Vec2& v) const;

	/**
	 * Used to calculate the cross product between two vectors
	 *
	 * @param [in] v The vector you want to calculate cross product for.
	 * \return float The cross product of the two vectors.
	 */
	float Cross(const Vec2& v) const;

	/**
	 * Used to normalize a vector2.
	 */
	Vec2 Normalized() const;

	/**
	 * Used to convert the vector2 to a string.
	 */
	std::string ToString() const;

	/**
	 * Returns the angle in degrees between this and to.
	 */
	float Angle(Vec2 to) const;

public:

	/* Class operations */
	
	// ASSINGMENT AND EQUALITY OPERATIONS
	inline Vec2& operator = (const Vec2& v) { x = v.x; y = v.y; return *this; }
	inline Vec2& operator = (const float& f) { x = f; y = f; return *this; }
	inline Vec2& operator - (void) { x = -x; y = -y; return *this; }
	inline bool operator == (const Vec2& v) const { return (x == v.x) && (y == v.y); }
	inline bool operator != (const Vec2& v) const { return (x != v.x) || (y != v.y); }

	// VECTOR2 TO VECTOR2 OPERATIONS
	inline const Vec2 operator + (const Vec2& v) const { return Vec2(x + v.x, y + v.y); }
	inline const Vec2 operator - (const Vec2& v) const { return Vec2(x - v.x, y - v.y); }
	inline const Vec2 operator * (const Vec2& v) const { return Vec2(x * v.x, y * v.y); }
	inline const Vec2 operator / (const Vec2& v) const { return Vec2(x / v.x, y / v.y); }

	// VECTOR2 TO THIS OPERATIONS
	inline Vec2& operator += (const Vec2& v) { x += v.x; y += v.y; return *this; }
	inline Vec2& operator -= (const Vec2& v) { x -= v.x; y -= v.y; return *this; }
	inline Vec2& operator *= (const Vec2& v) { x *= v.x; y *= v.y; return *this; }
	inline Vec2& operator /= (const Vec2& v) { x /= v.x; y /= v.y; return *this; }

	// SCALER TO VECTOR2 OPERATIONS
	inline const Vec2 operator + (float v) const { return Vec2(x + v, y + v); }
	inline const Vec2 operator - (float v) const { return Vec2(x - v, y - v); }
	inline const Vec2 operator * (float v) const { return Vec2(x * v, y * v); }
	inline const Vec2 operator / (float v) const { return Vec2(x / v, y / v); }

	// SCALER TO THIS OPERATIONS
	inline Vec2& operator += (float v) { x += v; y += v; return *this; }
	inline Vec2& operator -= (float v) { x -= v; y -= v; return *this; }
	inline Vec2& operator *= (float v) { x *= v; y *= v; return *this; }
	inline Vec2& operator /= (float v) { x /= v; y /= v; return *this; }

public: // Public fields

	float x; // The x-axis value.
	float y; // The y-axis value.
};


#endif // _VEC2_HPP