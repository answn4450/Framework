#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager::SceneManager() : SceneState(nullptr)
{
	// ** ±âº»ÀûÀÎ ¾À Èå¸§ ¼³Á¤.
	SceneList = new NODE;
	SceneList->next = nullptr;
	SceneList->value = LOGO;
	SceneListPush(MENU);
	SceneListPush(STAGE);
}

SceneManager::~SceneManager()
{

}


void SceneManager::SetScene(SCENEID _State)
{
	if (SceneState != nullptr)
		::Safe_Release(SceneState);

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
	SceneState->Start();
}


void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render(HDC hdc)
{
	SceneState->Render(hdc);
}

void SceneManager::Destroy()
{
	delete SceneState;
	SceneState = nullptr;
}


void SceneManager::SceneListPush(SCENEID state)
{
	NODE* nextNode = SceneList;

	while (nextNode->next != nullptr)
		nextNode = nextNode->next;

	//** create
	nextNode->next = new NODE;

	//** initialize
	nextNode->next->next = nullptr;
	nextNode->next->value = state;
}

void SceneManager::NextScene()
{
	if (SceneList->next != nullptr)
	{
		SceneList = SceneList->next;

		switch (SceneList->value)
		{
		case LOGO:
			SetScene(LOGO);
			break;

		case MENU:
			SetScene(MENU);
			break;

		case STAGE:
			SetScene(STAGE);
			break;
		}
	}
}