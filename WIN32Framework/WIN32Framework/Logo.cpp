#include "Logo.h"
#include "SceneManager.h"

void Logo::Start()
{
}

void Logo::Update()
{
	if (GetAsyncKeyState('A'))
	{
		GetSingle(SceneManager)->SetScene(MENU);
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
