#pragma once

class Game
{
public:
    // ゲーム固有の初期化
    bool Initialize();

    //　ゲームの更新処理
    void Update(float deltaTime);

    // ゲームの描画処理
    void Render();

    //　ゲーム固有の終了処理
    void Finalize();
};