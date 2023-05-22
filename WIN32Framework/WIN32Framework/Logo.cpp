#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

void Logo::Start()
{
}

void Logo::Update()
{
	DWORD dwKey = GET_SINGLE(InputManager)->GetKey();
	if (dwKey & KEYID_SPACE)
	{
		//GET_SINGLE(SceneManager)->SetScene(MENU);
		GET_SINGLE(SceneManager)->NextScene();
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
