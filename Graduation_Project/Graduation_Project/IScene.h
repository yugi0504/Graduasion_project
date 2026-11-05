#pragma once

#include <vector>
#include <memory>

#include "GameObject.h"

class IScene
{
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~IScene() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns></returns>
	virtual bool Initialize() = 0;

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="deltaTime">経過時間</param>
	virtual void Update(float deltaTime) = 0;

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Render() = 0;

	/// <summary>
	/// 終了
	/// </summary>
	virtual void Finalize() = 0;
};