#include "Matrix4x4.h"
#include <cmath>

Matrix4x4 Matrix4x4::Identity()
{
	Matrix4x4 matrix;

	for (int i = 0; i < 4; i++)
	{
		matrix.m[i][i] = 1.0f;
	}

	return matrix;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const
{
	Matrix4x4 result;

	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			for (int k = 0; k < 4; ++k)
			{
				result.m[row][column] += m[row][k] * other.m[k][column];
			}
		}
	}

	return result;
}

Matrix4x4 Matrix4x4::CreateTranslation(const Vector3& position)
{
	Matrix4x4 matrix = Identity();

	matrix.m[0][3] = position.x;
	matrix.m[1][3] = position.y;
	matrix.m[2][3] = position.z;

	return matrix;
}

Matrix4x4 Matrix4x4::CreateScale(const Vector3& scale)
{
	Matrix4x4 matrix = Identity();

	matrix.m[0][0] = scale.x;
	matrix.m[1][1] = scale.y;
	matrix.m[2][2] = scale.z;

	return matrix;
}

Matrix4x4 Matrix4x4::CreateRotationX(float angle)
{
	Matrix4x4 matrix = Identity();

	const float cosValue = std::cos(angle);
	const float sinValue = std::sin(angle);

	matrix.m[1][1] = cosValue;
	matrix.m[1][2] = -sinValue;
	matrix.m[2][1] = sinValue;
	matrix.m[2][2] = cosValue;

	return matrix;

}

Matrix4x4 Matrix4x4::CreateRotationY(float angle)
{
	Matrix4x4 matrix = Identity();

	const float cosValue = std::cos(angle);
	const float sinValue = std::sin(angle);

	matrix.m[0][0] = cosValue;
	matrix.m[0][2] = sinValue;
	matrix.m[2][0] = -sinValue;
	matrix.m[2][2] = cosValue;

	return matrix;
}

Matrix4x4 Matrix4x4::CreateRotationZ(float angle)
{
	Matrix4x4 matrix = Identity();

	const float cosValue = std::cos(angle);
	const float sinValue = std::sin(angle);

	matrix.m[0][0] = cosValue;
	matrix.m[0][1] = -sinValue;
	matrix.m[1][0] = sinValue;
	matrix.m[1][1] = cosValue;

	return matrix;
}

Matrix4x4 Matrix4x4::CreateTransform(const Vector3& position,const Vector3& rotation,const Vector3& scale)
{
	const Matrix4x4 translationMatrix = CreateTranslation(position);

	const Matrix4x4 rotationXMatrix = CreateRotationX(rotation.x);

	const Matrix4x4 rotationYMatrix = CreateRotationY(rotation.y);

	const Matrix4x4 rotationZMatrix = CreateRotationZ(rotation.z);

	const Matrix4x4 scaleMatrix = CreateScale(scale);

	return translationMatrix * rotationZMatrix * rotationYMatrix * rotationXMatrix * scaleMatrix;
}