#include "Bullet.h"
#include "G_Enemy.h"

GameObject* Bullet::Start()
{
	transform.position = Vector3(700.0f, 350.0f, 0.0f);
	transform.direction = Vector3(-1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(10.0f, 10.0f, 0.0f);

	Speed = 15.0f;

	Key = "Bullet";

	return this;
}

void Bullet::Start(Vector3 _position)
{
	transform.position = _position;
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(10.0f, 10.0f, 0.0f);

	Speed = 15.0f;

	Key = "Bullet";
}

int Bullet::Update()
{
	transform.position.x += Speed;
	//transform.position = g_enemy->GetPosition();
	if (transform.position.x > WIDTH)
		return 1;

	return 0;
}


void Bullet::Render(HDC hdc)
{
	Rectangle(hdc,
		(int)(transform.position.x - transform.scale.x * 0.5f),
		(int)(transform.position.y - transform.scale.y * 0.5f),
		(int)(transform.position.x + transform.scale.x * 0.5f),
		(int)(transform.position.y + transform.scale.y * 0.5f)
	);
}

void Bullet::Destroy()
{
}

void Bullet::Collide()
{
}

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}