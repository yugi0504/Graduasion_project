#include "GameObject.h"
#include <utility>
#include <algorithm>

// コンストラクタ
GameObject::GameObject(const std::string& name)
	: m_name(name)
{

}

// オブジェクト名の取得
const  std::string& GameObject::GetName() const noexcept
{
	return m_name;
}

// オブジェクト名の設定
void GameObject::SetName(const std::string& name) noexcept
{
	m_name = name;
}

// 親オブジェクトの取得
GameObject* GameObject::GetParent() noexcept
{
	return m_parent;
}

// 親オブジェクトの設定
void GameObject::SetParent(GameObject* parent) noexcept
{
	m_parent = parent;
}

// 子オブジェクトの追加
GameObject* GameObject::AddChild(std::unique_ptr<GameObject> child)
{
	if (child == nullptr)
	{
		return nullptr;
	}

	// 自分自身を子オブジェクトとして追加しようとした場合は追加しない
	if (child.get() == this)
	{
		return nullptr;
	}

	// すでに親オブジェクトが設定されている場合は追加しない
	if (child->GetParent() != nullptr)
	{
		return nullptr;
	}

	// 子オブジェクトが自分自身の祖先である場合は追加しない
	GameObject* ancestor = this;

	while (ancestor != nullptr)
	{
		if (ancestor == child.get())
		{
			return nullptr;
		}
		ancestor = ancestor->GetParent();
	}

	// 親オブジェクトを設定
	child->SetParent(this);

	// 追加された子オブジェクトのポインタを取得
	GameObject* childPtr = child.get();

	// 子オブジェクトをリストに追加
	m_children.push_back(std::move(child));

	// 追加された子オブジェクトのポインタを返す
	return childPtr;
}

// 子オブジェクトの削除
bool GameObject::RemoveChild(GameObject* child)
{
	if (child == nullptr)
	{
		return false;
	}

	// 子オブジェクトのリストから削除
	auto it = std::find_if(m_children.begin(), m_children.end(),[child](const std::unique_ptr<GameObject>& ptr) 
		{ 
			return ptr.get() == child; 
		}
	);
	
	// 子オブジェクトが見つからなかった場合は削除できない
	if (it == m_children.end())
	{
		return false;
	}

	// 親オブジェクトを解除
	(*it)->SetParent(nullptr);

	// 子オブジェクトをリストから削除
	m_children.erase(it);
	return true;
}

// 子オブジェクトリストの取得
const std::vector<std::unique_ptr<GameObject>>& GameObject::GetChildren() const noexcept
{
	return m_children;
}

// 子オブジェクトの数を取得
size_t GameObject::GetChildCount() const noexcept
{
	return m_children.size();
}