#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"

void Menu::Start()
{
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey && KEYID_RETURN)
	{
		Sleep(100);
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
