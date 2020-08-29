#ifndef _Matrix3X4_HPP
#define _Matrix3X4_HPP

/* Represents a 3x4 Matrix4x4 */
struct Matrix3x4
{
	union
	{
		struct
		{
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
		};
		float m[3][4];
	};
};

/* Used to transpose a 3x4 Matrix4x4 */
Matrix3x4* Matrix3x4Transpose(Matrix3x4* pout, const Matrix3x4* pm);

#endif // _Matrix4x43X4_HPP