#include "GameMath.hpp"

/* Implementation for W2S */
Vec2 W2S(Vec3 origin, Matrix4x4* view_Matrix4x4, uint64_t camera)
{
	Matrix4x4 temp;

	/* Read the Matrix4x4 so that it is always accurate for drawing */
	//*view_Matrix4x4 = //rust->Read<Matrix4x4>(camera + 0x2E4);

	Matrix4x4Transpose(&temp, view_Matrix4x4);

	Vec3 translationVector = Vec3(temp._41, temp._42, temp._43);
	Vec3 up = Vec3(temp._21, temp._22, temp._23);
	Vec3 right = Vec3(temp._11, temp._12, temp._13);

	float w = Vec3Dot(&translationVector, &origin) + temp._44;

	/* Check that the position is within bounds */
	if (w < 0.098f)
		return { 0.0f, 0.0f };

	/* Calculate the dot product to get x, and y. */
	float y = Vec3Dot(&up, &origin) + temp._24;
	float x = Vec3Dot(&right, &origin) + temp._14;

	/* Output vector for this function, the screen position */
	return Vec2
	{		
		//(render->render_size.x / 2.0f) * (1.f + x / w),
		//(render->render_size.y / 2.0f) * (1.f - y / w)
	};
}

