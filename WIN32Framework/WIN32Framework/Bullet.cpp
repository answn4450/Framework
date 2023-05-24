#include "Bullet.h"
#include "G_Enemy.h"
#include "ObjectPool.h"
#include "NormalBullet.h"

GameObject* Bullet::Start()
{
	transform.position = Vector3(700.0f, 350.0f, 0.0f);
	transform.direction = Vector3(1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(10.0f, 10.0f, 0.0f);

	Speed = 15.0f;

	Key = "Bullet";

	bulletBridge = new NormalBullet;
	bulletBridge->SetObject(this);
	if (bulletBridge)
		bulletBridge->Start();

	return this;
}

void Bullet::Start(Vector3 _position)
{
	transform.position = _position;
	transform.direction = Vector3(1.0f, 0.0f, 0.0f);
	transform.scale = Vector3(10.0f, 10.0f, 0.0f);
	
	bulletBridge = new NormalBullet;
	bulletBridge->SetObject(this);
	if (bulletBridge)
		bulletBridge->Start();

	Key = "Bullet";
}

int Bullet::Update()
{
	if (bulletBridge)
		bulletBridge->Update(transform);

	if (transform.position.x > WIDTH)
		return 1;

	return 0;
}


void Bullet::Render(HDC hdc)
{
	if (bulletBridge)
		bulletBridge->Render(hdc);
}

void Bullet::Destroy()
{
	GET_SINGLE(ObjectPool)->ReturnObject(this);

	// Destory 실행 표시
	transform.direction = Vector3(-1.0f, 0.0f, 0.0f);
}

void Bullet::Collide()
{
}

Bullet::Bullet() : bulletBridge(nullptr)
{
}

Bullet::~Bullet()
{
}