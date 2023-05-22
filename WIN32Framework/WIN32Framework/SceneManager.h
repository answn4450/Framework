#pragma once

#include "Include.h"

class Scene;
class SceneManager
{
public:
	SINGLE(SceneManager)
private:
	Scene* SceneState;
	NODE* SceneList;
	void SceneListPush(SCENEID state);
public:
	void SetScene(SCENEID _State);
	void NextScene();
	void Update();
	void Render(HDC hdc);
	void Destroy();
private:
	SceneManager();
public:
	~SceneManager();
};
