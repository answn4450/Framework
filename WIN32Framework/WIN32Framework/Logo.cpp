#include "Logo.h"

void Logo::Start()
{
}

int Logo::Update()
{
	if (GetAsyncKeyState('S'))
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
	return 0;
}

void Logo::Render(HDC hdc)
{
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
