#pragma once

#include <array>
#include "KeyCode.h"

class Input
{
public:
    // シングルトンインスタンスを取得
    static Input& GetInstance() noexcept;

    // 入力状態を更新
    void Update() noexcept;

    // キーが押されているか
    bool IsKeyDown(KeyCode keyCode) const noexcept;

    // キーが押された瞬間か
    bool IsKeyTriggered(KeyCode keyCode) const noexcept;

    // キーが離された瞬間か
    bool IsKeyReleased(KeyCode keyCode) const noexcept;

private:
    // 外部からのインスタンス生成を禁止
    Input() = default;

    // コピーを禁止
    Input(const Input&) = delete;
    Input& operator=(const Input&) = delete;

    static constexpr int KeyCount = 256;

    // YEngineのキーコードをDxLibのキーコードに変換
    int ConvertKeyCode(KeyCode keyCode) const noexcept;

    // 現在と前回の入力状態
    std::array<char, KeyCount> currentKeyState{};
    std::array<char, KeyCount> previousKeyState{};
};
