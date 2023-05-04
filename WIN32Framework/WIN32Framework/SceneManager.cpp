#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"


void SceneManager::SetScene(SCENEID _State)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr
	}

	switch (_State)
	{
	case LOGO:
		SceneState = new Logo;
		break;

	case MENU:
		SceneState = new Menu;
		break;

	case STAGE:
		SceneState = new Stage;
		break;
	}
}

int SceneManager::Update()
{
	SceneState->Update();

	return 0;
}

void SceneManager::Render(HDC hdc)
{
	SceneState->Render(hdc);
}

void SceneManager::Destroy()
{
	SceneState->Destroy();
}

SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}
