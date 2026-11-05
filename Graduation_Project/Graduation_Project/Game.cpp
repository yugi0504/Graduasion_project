#include "Game.h"
#include "GameObject.h"

#include <memory>
#include <cassert>

#include "DxLib.h"

bool Game::Initialize()
{
    // 親オブジェクトの生成
    GameObject player("Player");

    // 子オブジェクトを2つ追加
    player.AddChild(std::make_unique<GameObject>("Weapon"));
    player.AddChild(std::make_unique<GameObject>("Camera"));

    // 子オブジェクト数を確認
    assert(player.GetChildCount() == 2);

    // 子オブジェクトを1つ削除
    GameObject* weapon = player.GetChildren()[0].get();

    assert(player.RemoveChild(weapon) == true);

    // 削除後の子オブジェクト数を確認
    assert(player.GetChildCount() == 1);

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
