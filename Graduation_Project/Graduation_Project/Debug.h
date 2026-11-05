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
	void Update(float deltaTime) noexcept;

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
	void DrawFPS() const;
	void DrawDeltaTime() const;

	bool m_isEnabled = true;

	// デバッグ表示設定
	int m_textX = 20;
	int m_textY = 50;
	int m_lineSpacing = 20;

	// デバッグ文字色
	int m_textColor = 0;

	// FPS計測用
	int m_currentFPS = 0;
	int m_frameCount = 0;
	int m_fpsUpdateTime = 0;

	// 時間情報
	float m_deltaTime = 0.0f;
};

