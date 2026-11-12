#pragma once

struct Vector3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	// ------------------------------------------------------------- // 
	// ベクトル演算
	// ------------------------------------------------------------- //

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	Vector3 operator*(float scalar) const;

	// ------------------------------------------------------------- //
	// ベクトル計算
	// ------------------------------------------------------------- //

	/// <summary>
	/// ベクトルの長さ
	/// </summary>
	/// <returns>ベクトルの長さ</returns>
	float Length() const;
	/// <summary>
	/// ベクトルの正規化
	/// </summary>
	/// <returns>正規化されたベクトル</returns>
	Vector3 Normalized() const;
	/// <summary>
	/// ベクトルの内積
	/// </summary>
	/// <param name="other">異なるベクトル</param>
	/// <returns>二つのベクトルの内積</returns>
	float Dot(const Vector3& other) const;
	/// <summary>
	/// 外積
	/// </summary>
	/// <param name="other">異なるベクトル</param>
	/// <returns>二つのベクトルの外積</returns>
	Vector3 Cross(const Vector3& other) const;
};

