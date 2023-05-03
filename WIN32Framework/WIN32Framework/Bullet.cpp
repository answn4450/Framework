#include "Bullet.h"

void Bullet::Start()
{
	transform.position = Vector3(700.0f, 350.0f, 0.0f);
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(10.0f, 10.0f, 0.0f);

	Speed = 10.0f;
}

/*
void Bullet::Start(Vector3 _position)
{
	transform.position = _position;
	transform.rotation = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(100.0f, 100.0f, 0.0f);
}
*/

int Bullet::Update()
{
	transform.position.x += Speed;

	if (transform.position.x > WIDTH)
		return 1;

	return 0;
}

void Bullet::Render(HDC hdc)
{
	Rectangle(hdc,
		(int)transform.position.x - transform.scale.x * 0.5f,
		(int)transform.position.y - transform.scale.y * 0.5f,
		(int)transform.position.x + transform.scale.x * 0.5f,
		(int)transform.position.y + transform.scale.y * 0.5f
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