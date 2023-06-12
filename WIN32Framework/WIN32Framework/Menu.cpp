#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "include.h"

void Menu::Start()
{
}

void Menu::Update()
{
	DWORD dwKey = GET_SINGLE(InputManager)->GetKey();
	if (dwKey & KEYID_RETURN)
	{
		//GET_SINGLE(SceneManager)->SetScene(STAGE);
		GET_SINGLE(SceneManager)->NextScene();
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