#include "NormalBullet.h"
#include "Bullet.h"

NormalBullet::NormalBullet()
{
}

NormalBullet::~NormalBullet()
{
}

void NormalBullet::Start()
{
	Speed = 3.5f;
	BulletBridgeKey = "NormalBullet";
}

void NormalBullet::Update(Transform& transform)
{
	transform.position += transform.direction * Speed;
}

void NormalBullet::Render(HDC hdc)
{
	Rectangle(hdc,
		(int)(Object->GetPosition().x - Object->GetScale().x * 0.5f),
		(int)(Object->GetPosition().y - Object->GetScale().y * 0.5f),
		(int)(Object->GetPosition().x + Object->GetScale().x * 0.5f),
		(int)(Object->GetPosition().y + Object->GetScale().y * 0.5f)
	);
}

void NormalBullet::Destroy()
{
}
