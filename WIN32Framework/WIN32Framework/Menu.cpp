#include "Menu.h"
#include "SceneManager.h"

void Menu::Start()
{
}

int Menu::Update()
{
	if (GetAsyncKeyState('A'))
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
	return 0;
}

void Menu::Render(HDC hdc)
{
}

void Menu::Destroy()
{
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
