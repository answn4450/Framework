#include "Menu.h"
#include "SceneManager.h"

void Menu::Start()
{
}

void Menu::Update()
{
	if (GetAsyncKeyState('S'))
	{
		SceneManager::GetInstance()->SetScene(STAGE);
	}
}

void Menu::Render(HDC hdc)
{
	Rectangle(hdc, 500, 100, 600, 600);
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
