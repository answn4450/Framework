#pragma once

#include "Include.h"


class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
	HDC m_hdc;

	RECT rcPoint;
	GameObject* m_pPlayer;
	GameObject* m_pEnemy;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == NULL)
			Instance = new SceneManager;
		return Instance;
	}
private:
	Scene* SceneState;
public:
	void SetScene(SCENEID _State);
	int Update();
	void Render(HDC hdc);
	void Destroy();
private:
	SceneManager();
public:
	~SceneManager();
};


SceneManager* SceneManager::Instance = nullptr;