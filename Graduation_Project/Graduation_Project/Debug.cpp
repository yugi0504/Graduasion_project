#include "Debug.h"
#include "DxLib.h"

// デバッグ機能の初期化
void Debug::Initialize() noexcept
{
    m_isEnabled = true;

    m_currentFPS = 0;
    m_frameCount = 0;
    m_fpsUpdateTime = GetNowCount();
}

// デバッグ情報の更新
void Debug::Update() noexcept
{
    if (!m_isEnabled)
    {
        return;
    }

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

    DrawFormatString(20,50,GetColor(255, 255, 0), "FPS: %d",m_currentFPS);
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
