#include "Time.h"
#include "DxLib.h"

Time& Time::GetInstance() noexcept
{
    static Time instance;
    return instance;
}

void Time::Initialize()
{
    previousTime = GetNowCount();
    deltaTime = 0.0f;
}

void Time::Update() noexcept
{
    const int currentTime = GetNowCount();

    deltaTime = (currentTime - previousTime) / 1000.0f;

    // フレーム停止などによる大きな時間変化を制限
    if (deltaTime > 0.1f)
    {
        deltaTime = 0.1f;
    }

    previousTime = currentTime;
}

float Time::GetDeltaTime() const noexcept
{
    return deltaTime;
}
