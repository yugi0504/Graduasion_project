#include "Engine.h"
#include "Game.h"
#include "Time.h"
#include "Input.h"
#include "DxLib.h"

bool Engine::Initialize(Game* game, const WindowConfig& windowConfig,const EngineConfig& engineConfig)
{
    // ゲームが設定されていない場合は初期化しない
    if (game == nullptr)
    {
        return false;
    }

    // ウィンドウ設定が不正の場合は初期化しない
    if (!windowConfig.IsValid())
    {
        return false;
    }

    // エンジン設定が不正の場合は初期化しない
    if (!engineConfig.IsValid())
    {
        return false;
    }

    m_currentGame = game;
    m_targetFPS = engineConfig.targetFPS;

    // ウィンドウモードに設定
    ChangeWindowMode(windowConfig.isWindowMode ? TRUE : FALSE);

    // ウィドウサイズを変更
    SetGraphMode(windowConfig.width, windowConfig.height, 32);

    // DxLibの初期化
    if (DxLib_Init() == -1)
    {
        m_currentGame = nullptr;
        return false;
    }

    // 背景色を設定
    SetBackgroundColor(windowConfig.backgroundR,windowConfig.backgroundG ,windowConfig.backgroundB );

    // 時間管理を初期化
    Time::GetInstance().Initialize();

    // ゲーム固有の初期化
    if (!m_currentGame->Initialize())
    {
        DxLib_End();
        m_currentGame = nullptr;
        return false;
    }

    // 初期化成功
    m_isInitialized = true;
    m_isRunning = true;

    return true;
}

void Engine::Run()
{
    if (!m_isInitialized || m_currentGame == nullptr)
    {
        return;
    }

    // 目標フレーム時間(ミリ秒)
    const double targetFrameTime = 1000.0 / m_targetFPS;

    while (m_isRunning)
    {
        // フレーム開始時刻を取得
        const int frameStartTime = GetNowCount();

        // ウィンドウメッセージを処理
        if (ProcessMessage() != 0)
        {
            m_isRunning = false;
            break;
        }

        // 入力状態を更新
        Input::GetInstance().Update();

        // Escapeキーで終了
        if (Input::GetInstance().IsKeyTriggered(KeyCode::Escape))
        {
            m_isRunning = false;
            break;
        }

        // 時間情報を更新
        Time::GetInstance().Update();

        // 画面をクリア
        ClearDrawScreen();

        // ゲームの更新処理
        m_currentGame->Update(Time::GetInstance().GetDeltaTime());

        // ゲームの描画処理
        m_currentGame->Render();

        // 描画結果を画面に反映
        ScreenFlip();

        // フレーム処理にかかった時間を取得
        const int elapsedTime = GetNowCount() - frameStartTime;

        // 目標時間までの残り時間を計算
        const int waitTime = static_cast<int>(targetFrameTime - elapsedTime);

        // 必要な場合のみ待機
        if (waitTime > 0)
        {
            WaitTimer(waitTime);
        }
    }
}

void Engine::Finalize()
{
    // 初期化されてない場合は処理しない
    if (!m_isInitialized)
    {
        return;
    }

    m_isRunning = false;

    // ゲーム固有の終了処理
    if (m_currentGame != nullptr)
    {
        m_currentGame->Finalize();
        m_currentGame = nullptr;
    }

    // DxLibの終了
    DxLib_End();
}
