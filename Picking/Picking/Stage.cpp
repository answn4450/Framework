#include "Stage.h"
#include "Tile.h"
#include "Bitmap.h"

void Stage::Start()
{
	object = new Tile;
	object->Start();
	//background = (new Bitmap)->LoadBmp(L"../Resource/BackGround1.bmp");
	//background = (new Bitmap)->LoadBmp(L"../Resource/Tile.bmp");
	
	//(*m_mapImageList)["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Buffer.bmp");
	background = (new Bitmap)->LoadBmp(L"../Resource/Stage/Tile.bmp");
}

int Stage::Update()
{
	object->Update();
	return 0;
}

void Stage::Render(HDC hdc)
{
	//object->Render(hdc);

	TransparentBlt(hdc,
		0, 0, 128, 64,
		background->GetMemDC(),
		0,
		0,
		128,
		64,
		RGB(255, 0, 255));
	
	for (int y = 0; y < HEIGHT; y += 64)
	{
		for (int x = 0; x < WIDTH; x += 128)
		{
			TransparentBlt(hdc,
				x, 
				y, 
				128, 
				64,
				background->GetMemDC(),
				0,
				0,
				128,
				64,
				RGB(255, 0, 255));
		}
	}
	/*
	*/
	
	
	/*
	BitBlt((*m_mapImageList)["Buffer"]->GetMemDC(),			// ������ ���� �׸��� ?!
		0, 0, WIDTH, HEIGHT,		// ������ ���� ���������κ��� ���κб���
		(*m_mapImageList)["BackGround"]->GetMemDC(),		// ������ �̹���
		0, 0,				// �������� ����ش�.
		SRCCOPY);			// �ҽ� ������ ��� ������ �����Ѵ�.
	*/

}

void Stage::Destroy()
{
	object->Destroy();

}

Stage::Stage()
{
}

Stage::~Stage()
{
}
