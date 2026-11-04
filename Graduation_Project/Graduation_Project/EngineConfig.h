#pragma once

/// <summary>
/// エンジン全体の設定
/// </summary>
struct EngineConfig
{
	// 目標FPS
	int targetFPS = 60;

	/// <summary>
	/// 設定値が有効か確認
	/// </summary>
	/// <returns>true:有効 false:無効</returns>
	bool IsValid() const noexcept
	{
		return targetFPS > 0;
	}
};