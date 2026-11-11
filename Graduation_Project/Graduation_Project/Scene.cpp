#include "Scene.h"

// ‰Šú‰»
bool Scene::Initialize()
{
	return true;
}

// XV
void Scene::Update(float deltaTime)
{

}

// •`‰æ
void Scene::Render()
{

}

// I—¹ˆ—
void Scene::Finalize()
{

}

GameObject* Scene::AddGameObject(std::unique_ptr<GameObject>&& gameObject)
{
	if (gameObject == nullptr)
	{
		return nullptr;
	}

	if (gameObject->GetParent() != nullptr)
	{
		return nullptr;
	}

	GameObject* addedGameObject = gameObject.get();

	m_gameObjects.push_back(std::move(gameObject));

	return addedGameObject;
}

GameObject* Scene::FindGameObject(const std::string& name) const
{
	for (const auto& gameObject : m_gameObjects)
	{
		if (gameObject->GetName() == name)
		{
			return gameObject.get();
		}
	}

	return nullptr;
}

bool Scene::RemoveGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr)
	{
		return false;
	}

	auto it = std::find_if(
		m_gameObjects.begin(), m_gameObjects.end(),
		[gameObject](const std::unique_ptr<GameObject>& object)
		{
			return object.get() == gameObject;
		}
	);

	if (it == m_gameObjects.end())
	{
		return false;
	}

	m_gameObjects.erase(it);

	return true;
}