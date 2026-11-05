#include "Debug.h"
#include "DxLib.h"

// デバッグ機能の初期化
void Debug::Initialize() noexcept
{
    m_isEnabled = true;

    m_currentFPS = 0;
    m_frameCount = 0;
    m_fpsUpdateTime = GetNowCount();

	// デバッグ表示設定の初期化
    m_textX = 20;
	m_textY = 50;
	m_lineSpacing = 20;

	// デバッグ文字色を黄色に設定
	m_textColor = GetColor(255, 255, 0);

	// 時間情報の初期化
	m_deltaTime = 0.0f;
}

// デバッグ情報の更新
void Debug::Update(float deltaTime) noexcept
{
    if (!m_isEnabled)
    {
        return;
    }

    m_deltaTime = deltaTime;

    // フレーム数を加算
    ++m_frameCount;

    // 現在時刻を取得
    const int currentTime = GetNowCount();

    // FPS計測期間
    const int fpsElapsedTime = currentTime - m_fpsUpdateTime;

    // 1秒以上経過した場合
    if (fpsElapsedTime >= 1000)
    {
        // FPSを計算
        m_currentFPS = static_cast<int>( m_frameCount * 1000.0 / fpsElapsedTime);

        // 計測情報をリセット
        m_frameCount = 0;
        m_fpsUpdateTime = currentTime;
    }
}

// デバッグ情報の描画
void Debug::Render() const
{
    if (!m_isEnabled)
    {
        return;
    }

	// FPSの描画
	DrawFPS();

	// DeltaTimeの描画
    DrawDeltaTime();
}

// デバッグ機能の終了処理
void Debug::Finalize() noexcept
{
    m_currentFPS = 0;
    m_frameCount = 0;
    m_fpsUpdateTime = 0;
}

// デバッグ表示の有効・無効を切り替える
void Debug::SetEnabled(bool isEnabled) noexcept
{
    m_isEnabled = isEnabled;
}

// デバッグ情報の描画（FPS表示）
void Debug::DrawFPS() const
{
	DrawFormatString(m_textX, m_textY, m_textColor, "FPS: %d", m_currentFPS);
}

void Debug::DrawDeltaTime() const
{
	DrawFormatString(m_textX, m_textY + m_lineSpacing, m_textColor, "DeltaTime: %.4f sec", m_deltaTime);
}