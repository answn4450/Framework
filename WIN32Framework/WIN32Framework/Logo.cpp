#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

void Logo::Start()
{
}

void Logo::Update()
{
	DWORD dwKey = GetSingle(InputManager)->GetKey();
	if (dwKey & KEYID_SPACE)
	{
		//GetSingle(SceneManager)->SetScene(MENU);
		GetSingle(SceneManager)->NextScene();
	}
}

void Logo::Render(HDC hdc)
{
	Rectangle(hdc, 500, 500, 600, 600);
}

void Logo::Destroy()
{
}

Logo::Logo()
{
}

Logo::~Logo()
{
}
