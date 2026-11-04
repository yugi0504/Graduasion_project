#include "Input.h"
#include "DxLib.h"

Input& Input::GetInstance() noexcept
{
    static Input instance;
    return instance;
}

void Input::Update() noexcept
{
    // 前フレームの入力状態を保存
    previousKeyState = currentKeyState;

    // 現在のキーボード入力状態を取得
    const int result = GetHitKeyStateAll(currentKeyState.data());

    // 入力取得に失敗した場合は、入力状態を初期化
    if (result == -1)
    {
        currentKeyState.fill(0);
    }
}

int Input::ConvertKeyCode(KeyCode keyCode) const noexcept
{
    switch (keyCode)
    {
    case KeyCode::Escape:   return KEY_INPUT_ESCAPE;
    case KeyCode::Space:    return KEY_INPUT_SPACE;

    case KeyCode::W:        return KEY_INPUT_W;
    case KeyCode::A:        return KEY_INPUT_A;
    case KeyCode::S:        return KEY_INPUT_S;
    case KeyCode::D:        return KEY_INPUT_D;

    case KeyCode::Up:       return KEY_INPUT_UP;
    case KeyCode::Down:     return KEY_INPUT_DOWN;
    case KeyCode::Left:     return KEY_INPUT_LEFT;
    case KeyCode::Right:    return KEY_INPUT_RIGHT;

    case KeyCode::LeftShift: return KEY_INPUT_LSHIFT;

    default:                return -1;
    }
}

bool Input::IsKeyDown(KeyCode keyCode) const noexcept
{
    const int code = ConvertKeyCode(keyCode);

    if (code < 0 || code >= KeyCount)
    {
        return false;
    }

    return currentKeyState[code] != 0;
}

bool Input::IsKeyTriggered(KeyCode keyCode) const noexcept
{
    const int code = ConvertKeyCode(keyCode);

    if (code < 0 || code >= KeyCount)
    {
        return false;
    }

    return currentKeyState[code] != 0 && previousKeyState[code] == 0;
}

bool Input::IsKeyReleased(KeyCode keyCode) const noexcept
{
    const int code = ConvertKeyCode(keyCode);

    if (code < 0 || code >= KeyCount)
    {
        return false;
    }

    return currentKeyState[code] == 0 && previousKeyState[code] != 0;
}
