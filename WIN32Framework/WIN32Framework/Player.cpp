#include "Player.h"
//#include "GameObject.h"
#include "Bullet.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT *0.5f, 0.0f);
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);

	for (int i = 0; i < BULLETCOUNT; ++i)
	{
		bulletList[i] = nullptr;
	}
}

void Player::Update(GameObject* _other)
{
	if (GetAsyncKeyState(VK_UP))
	{
		transform.position.y -= 5.0f;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		transform.position.y += 5.0f;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		transform.position.x -= 5.0f;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		transform.position.x += 5.0f;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		CreateBullet();
	}

	int index = -1;
	for (int i = 0; i < BULLETCOUNT; ++i)
	{
		if (bulletList[i] != nullptr)
		{
			//if (bulletList[i]->Update(_other))
			if (bulletList[i]->Update())
			{
				index = i;
			}
		}
	}
}

int Player::Update() {
	if (GetAsyncKeyState(VK_UP))
	{
		transform.position.y -= 5.0f;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		transform.position.y += 5.0f;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		transform.position.x -= 5.0f;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		transform.position.x += 5.0f;
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		CreateBullet();
	}
	
	int index = -1;
	for (int i = 0; i < BULLETCOUNT; ++i)
	{
		if (bulletList[i] != nullptr)
		{
			if (bulletList[i]->Update())
			{
				index = i;
			}
		}
	}

	if (-1 < index)
	{
		delete bulletList[index];
		bulletList[index] = nullptr;
	}

	return 0;
}


void Player::Render(HDC hdc) {
	Rectangle(hdc,
		(int)(transform.position.x - transform.scale.x * 0.5f),
		(int)(transform.position.y - transform.scale.y * 0.5f),
		(int)(transform.position.x + transform.scale.x * 0.5f),
		(int)(transform.position.y + transform.scale.y * 0.5f)
	);

	for (int i = 0; i < BULLETCOUNT; ++i)
	{
		if (bulletList[i] != nullptr)
		{
			bulletList[i]->Render(hdc);
		}
	}
}

void Player::Destroy() {}


GameObject* Player::CreateBullet()
{
	GameObject* bullet = new Bullet;

	bullet->Start(transform.position);

	for (int i = 0; i < BULLETCOUNT; ++i)
	{
		if (bulletList[i] == nullptr)
		{
			bulletList[i]=bullet;
			break;
		}
	}

	return bullet;
}