#include "Game.h"
#include "DxLib.h"

bool Game::Initialize()
{
    // ゲーム固有の初期化処理
    return true;
}

void Game::Update(float deltaTime)
{
    // ゲーム内の更新処理をここに実装する
}

void Game::Render()
{
    // ゲーム画面の描画処理
    DrawString(20,20,"YEngine Start!",GetColor(255, 255, 255));
}

void Game::Finalize()
{
    // ゲーム固有の終了処理
}
