#pragma once

#include <vector>
#include <memory>
#include <string>


class GameObject
{
public:
	/// <summary>
	///	コンストラクタ
	/// </summary>
	/// <param name="name">オブジェクトの名前</param>
	explicit GameObject(const std::string& name);
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameObject() = default;

	/// <summary>
	/// オブジェクト名の取得
	/// </summary>
	/// <returns>オブジェクト名</returns>
	const std::string& GetName() const noexcept;

	/// <summary>
	/// オブジェクト名の設定
	/// </summary>
	/// <param name="name">オブジェクトの名前</param>
	void SetName(const std::string& name) noexcept;

	/// <summary>
	/// 親オブジェクトの取得
	/// </summary>
	GameObject* GetParent() noexcept;

	/// <summary>
	/// 親オブジェクトの設定
	/// </summary>
	/// <param name="parent">親オブジェクト</param>
	void SetParent(GameObject* parent) noexcept;

	/// <summary>
	/// 子オブジェクトの追加
	/// </summary>
	/// <param name="child">追加する子オブジェクト</param>
	/// <returns>追加された子オブジェクトのポインタ</returns>
	GameObject* AddChild(std::unique_ptr<GameObject> child);

	/// <summary>
	/// 子オブジェクトの削除
	/// </summary>
	/// <param name="child">削除する子オブジェクト</param>
	/// <returns>削除に成功した場合true、それ以外はfalse</returns>
	bool RemoveChild(GameObject* child);

	/// <summary>
	/// 子オブジェクトリストの取得
	/// </summary>
	/// <returns></returns>
	const std::vector<std::unique_ptr<GameObject>>& GetChildren() const noexcept;

	/// <summary>
	/// 子オブジェクトの数を取得
	/// </summary>
	/// <returns></returns>
	size_t GetChildCount() const noexcept;

private:
	// オブジェクト名
	std::string m_name;
	// 親オブジェクト
	GameObject* m_parent = nullptr;
	// 子オブジェクトのリスト
	std::vector<std::unique_ptr<GameObject>> m_children;
};