#pragma once
#include "Vector3.h"

struct Matrix4x4
{
	float m[4][4] = {};


	Matrix4x4 operator*(const Matrix4x4& other) const;


	static Matrix4x4 Identity();
	static Matrix4x4 CreateTranslation(const Vector3& position);
	static Matrix4x4 CreateScale(const Vector3& scale);
	static Matrix4x4 CreateRotationX(float angle);
	static Matrix4x4 CreateRotationY(float angle);
	static Matrix4x4 CreateRotationZ(float angle);
	static Matrix4x4 CreateTransform(const Vector3& position, const Vector3& rotation, const Vector3& scale);

};