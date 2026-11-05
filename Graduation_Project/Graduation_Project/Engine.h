#pragma once
#include "WindowConfig.h"
#include "EngineConfig.h"
#include "Debug.h"

class Game;

class Engine
{
public:
	/// <summary>
	/// エンジンの初期化
	/// </summary>
	/// <param name="game"></param>
	/// <param name="windowConfig"></param>
	/// <returns></returns>
	bool Initialize(Game* game, const WindowConfig& windowConfig,const EngineConfig& engineConfig);

	/// <summary>
	/// ゲームループの実行
	/// </summary>
	void Run();
	
	/// <summary>
	///  エンジンの終了処理
	/// </summary>
	void Finalize();

private:
	bool m_isRunning = false;
	bool m_isInitialized = false;
	bool m_isDebugEnabled = true;

	int m_targetFPS = 60;

	// デバッグ用のインスタンス
	Debug m_debug;

	// 現在実行中のゲームのインスタンス
	Game* m_currentGame = nullptr;
};