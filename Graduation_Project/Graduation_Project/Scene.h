#pragma once

#include "IScene.h"
#include "GameObject.h"

#include <memory>
#include <vector>

class Scene : public IScene
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Scene() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Scene() override = default;

	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns>初期化できたかどうか</returns>
	bool Initialize() override;

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="deltaTime">経過時間</param>
	void Update(float deltaTime) override;

	/// <summary>
	/// 描画
	/// </summary>
	void Render() override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// ゲームオブジェクトの追加
	/// </summary>
	/// <param name="gameObject">ゲームオブジェ</param>
	/// <returns>追加したGameObjectのポインタ</returns>
	GameObject* AddGameObject(std::unique_ptr<GameObject>&& gameObject);

	/// <summary>
	/// 名前を指定してGameObjectを取得する
	/// </summary>
	/// <param name="name">GameObjectの名前</param>
	/// <returns>該当するGameObjectのポインタ</returns>
	GameObject* FindGameObject(const std::string& name) const;

	/// <summary>
	/// 指定されたゲームオブジェクトが存在するか確認
	/// 存在する場合は削除
	/// </summary>
	/// <param name="gameObject">ゲームオブジェクト</param>
	/// <returns>trueが削除、falseが存在しない</returns>
	bool RemoveGameObject(GameObject* gameObject);

private:

	// ゲームオブジェクト一覧
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
};