#pragma once
class Debug
{
public:
	
	/// <summary>
	/// デバッグ機能の初期化
	/// </summary>
	void Initialize() noexcept;

	/// <summary>
	/// デバッグ情報の更新
	/// </summary>
	void Update() noexcept;

	/// <summary>
	/// デバッグ情報の描画
	/// </summary>
	void Render() const;

	/// <summary>
	/// デバッグ機能の終了処理
	/// </summary>
	void Finalize() noexcept;

	/// <summary>
	/// デバッグ表示の有効・無効を切り替える
	/// </summary>
	/// <param name="isEnabled">デバッグ表示が有効か無効か</param>
	void SetEnabled(bool isEnabled) noexcept;

private:
	bool m_isEnabled = true;

	// FPS計測用
	int m_currentFPS = 0;
	int m_frameCount = 0;
	int m_fpsUpdateTime = 0;
};

