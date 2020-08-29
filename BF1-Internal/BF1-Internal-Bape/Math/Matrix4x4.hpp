#ifndef _Matrix4X4_HPP
#define _Matrix4X4_HPP

/* Represents a 4x4 Matrix4x4 */
struct Matrix4x4
{
	union
	{
		struct
		{
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;
		};
		float m[4][4];
	};
};

/* Used to transpose a 4x4 Matrix4x4 */
Matrix4x4* Matrix4x4Transpose(Matrix4x4* pout, Matrix4x4* pm);

#endif // _Matrix4x4_HPP