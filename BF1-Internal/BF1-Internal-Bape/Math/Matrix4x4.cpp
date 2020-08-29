#include "Matrix4x4.hpp"

/* Implementation for Matrix4x4Transpose */
Matrix4x4* Matrix4x4Transpose(Matrix4x4* pout, Matrix4x4* pm)
{
	const Matrix4x4 m = *pm;
	int i, j;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++) pout->m[i][j] = m.m[j][i];

	return pout;
}