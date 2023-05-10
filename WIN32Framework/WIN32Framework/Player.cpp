#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "InputManager.h"


Player::Player()
{
}

Player::~Player()
{
}

GameObject* Player::Start()
{
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT *0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);

	return this;
}


int Player::Update() {
	DWORD dwKey = GetSingle(InputManager)->GetKey();
	if (dwKey & KEYID_UP)
	{
		transform.position.y -= 5.0f;
	}

	if (dwKey & KEYID_DOWN)
	{
		transform.position.y += 5.0f;
	}

	if (dwKey & KEYID_LEFT)
	{
		transform.position.x -= 5.0f;
	}

	if (dwKey & KEYID_RIGHT)
	{
		transform.position.x += 5.0f;
	}

	if (dwKey & KEYID_SPACE)
	{
		GetSingle(ObjectManager)->AddObjectList(CreateBullet());
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
}

void Player::Destroy() {}


GameObject* Player::CreateBullet()
{
	GameObject* bullet = new Bullet;

	bullet->Start(transform.position);
	
	
	return bullet;
}