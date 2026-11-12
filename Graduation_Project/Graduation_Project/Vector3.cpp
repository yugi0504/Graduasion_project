#include "Vector3.h"
#include <cmath>

// 加算
Vector3 Vector3::operator+(const Vector3& other) const
{
	return {
		x + other.x,
		y + other.y,
		z + other.z
	};
}

// 減算
Vector3 Vector3::operator-(const Vector3& other) const
{
	return {
	x - other.x,
	y - other.y,
	z - other.z
	};
}

// スカラー倍
Vector3 Vector3::operator*(float scalar) const
{
	return {
		x * scalar,
		y * scalar,
		z * scalar
	};
}

// 長さ
float Vector3::Length() const
{
	return std::sqrt(
		x * x +
		y * y +
		z * z
	);
}

// 正規化
Vector3 Vector3::Normalized() const
{
	const float length = Length();

	// 長さが0の場合は零ベクトルを返す
	if (length == 0.0f)
	{
		return{};
	}

	return {
		x / length,
		y / length,
		z / length
	};
}

// 内積
float Vector3::Dot(const Vector3& other) const
{
	return {
		x * other.x +
		y * other.y +
		z * other.z
	};
}

// 外積
Vector3 Vector3::Cross(const Vector3& other) const
{
	return {
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	};
}

