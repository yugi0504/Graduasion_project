
#pragma once

class Time
{
public:
    // シングルトンインスタンスを取得
    static Time& GetInstance() noexcept;

    // 時間管理の初期化
    void Initialize();

    // 時間情報の更新
    void Update() noexcept;

    // フレーム間の経過時間を取得
    float GetDeltaTime() const noexcept;

private:
    // 外部からのインスタンス生成を禁止
    Time() = default;

    // コピーを禁止
    Time(const Time&) = delete;
    Time& operator=(const Time&) = delete;

    int previousTime = 0;
    float deltaTime = 0.0f;
};
