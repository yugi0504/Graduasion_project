#include "Game.h"
#include "GameObject.h"
#include "Scene.h"

#include <memory>
#include <cassert>

#include "DxLib.h"

bool Game::Initialize()
{
    Scene scene;

    auto player = std::make_unique<GameObject>("Player");

    GameObject* addedPlayer = scene.AddGameObject(std::move(player));

    assert(addedPlayer != nullptr);

    assert(player == nullptr);

    // 名前で検索
    GameObject* foundPlayer = scene.FindGameObject("Player");

    assert(foundPlayer == addedPlayer);

    // 存在しない名前を検索
    assert(scene.FindGameObject("Enemy") == nullptr);

    // GameObjectを削除
    bool removed = scene.RemoveGameObject(addedPlayer);

    assert(removed);

    // 削除後に検索できないことを確認
    assert(scene.FindGameObject("Player") == nullptr);

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
