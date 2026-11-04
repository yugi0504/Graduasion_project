#include "Engine.h"
#include "Game.h"
#include "WindowConfig.h"
#include "EngineConfig.h"

#include "Dxlib.h"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
    Engine engine;
    Game game;

    WindowConfig windowConfig;
    EngineConfig engineConfig;

    // エンジンの初期化
    if (!engine.Initialize(&game,windowConfig,engineConfig))
    {
        return -1;
    }

    // ゲームループの実行
    engine.Run();

    // エンジンの終了処理
    engine.Finalize();

    return 0;
}
