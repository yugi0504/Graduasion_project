#pragma once

// ウィンドウ設定
struct WindowConfig
{
	// ウィンドウの解像度
	int width = 1280;
	int height = 720;

	// ウィンドウモード
	bool isWindowMode = true;

	// 背景色(RGB)
	int backgroundR = 30;
	int backgroundG = 30;
	int backgroundB = 30;

	/// <summary>
	/// 設定値が有効か確認
	/// </summary>
	/// <returns>true:有効 false:無効</returns>
	bool IsValid() const noexcept
	{
		// 解像度の確認
		if (width <= 0 || height <= 0)
		{
			return false;
		}

		// RGB値の確認
		if (backgroundR < 0 || backgroundR > 255 ||
			backgroundG < 0 || backgroundG > 255 ||
			backgroundB < 0 || backgroundB > 255)
		{
			return false;
		}

		return true;
	}
};