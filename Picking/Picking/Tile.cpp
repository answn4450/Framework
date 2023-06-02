#include "Tile.h"

void Tile::Start()
{
	position = Vector3(100.0f, 100.0f);
	scale = Vector3(100.0f, 100.0f);
}

int Tile::Update()
{
	POINT ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);
	

	if (check)
	{
		if (position.x - ptMouse.x < scale.x &&
			position.y - ptMouse.y < scale.y)
		/*
		if (position.x - scale.x * 0.5f < ptMouse.x &&
			position.x - scale.y * 0.5f < ptMouse.y &&
			position.x + scale.x * 0.5f > ptMouse.x &&
			position.x + scale.y * 0.5f > ptMouse.y)
		*/
		{
			/*
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				check = !check;
				Sleep(100);
			}
			check = 0;
			*/
			if (GetAsyncKeyState(VK_LBUTTON))
				check = 0;
		}
	}
	else
	{
		if (sqrt(
			(position.x - ptMouse.x) * (position.x - ptMouse.x) +
			(position.y - ptMouse.y) * (position.y - ptMouse.y)
		) < scale.x * 0.5f)
		{
			if (GetAsyncKeyState(VK_LBUTTON))
				check = 1;
			//check = !check;
			//Sleep(100);
		}
	}

	if (GetKeyState(VK_DOWN))
	{
		check = 1 - check;
		Sleep(100);
	}

	return 0;
}

void Tile::Render(HDC hdc)
{
	if (check)
		Rectangle(hdc, 
			position.x - scale.x * 0.5f, 
			position.y - scale.y * 0.5f, 
			position.x + scale.x * 0.5f, 
			position.y + scale.y * 0.5f
		);
	else
		Ellipse(hdc,
			position.x - scale.x * 0.5f,
			position.y - scale.y * 0.5f,
			position.x + scale.x * 0.5f,
			position.y + scale.y * 0.5f
		);
}

void Tile::Destroy()
{
}

Tile::Tile() : check(0)
{
}

Tile::~Tile()
{
}
