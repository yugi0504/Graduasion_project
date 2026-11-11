#pragma once

struct Vector3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;

};

Vector3 Vector3::operator+(const Vector3& other) const
{
	return {
		x + other.x,
		y + other.y,
		z + other.z
	};
}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return {
	x - other.x,
	y - other.y,
	z - other.z
	};
}