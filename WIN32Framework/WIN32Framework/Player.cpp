#include "Player.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ObjectPool.h"
#include "Prototype.h"

#include "NormalBullet.h"
#include "GuideBullet.h"
#include "Bitmap.h"

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
	transform.scale = Vector3(5500.0f, 3143.0f, 0.0f);

	Speed = 5.0f;

	Key = "BackGround";
	
	return this;
}


int Player::Update() {
	DWORD dwKey = GET_SINGLE(InputManager)->GetKey();
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
		GET_SINGLE(ObjectManager)->AddObject(CreateBullet<NormalBullet>("NormalBullet"));
	}
	
	if (dwKey & KEYID_CONTROL)
	{
		GET_SINGLE(ObjectManager)->AddObject(CreateBullet<GuideBullet>("GuideBullet"));
	}

	return 0;
}


void Player::Render(HDC hdc) {
	TransparentBlt(hdc,	  // 복사해 넣을 그림판 ?!
		(int)transform.position.x,	// 복사할 영역 시작점 X
		(int)transform.position.y, 	// 복사할 영역 시작점 Y
		(int)transform.scale.x,	// 복사할 영역 끝부분 X
		(int)transform.scale.y, 	// 복사할 영역 끝부분 Y
		(*m_ImageList)[Key]->GetMemDC(),	// 복사할 이미지 (복사대상)
		0,  // 복사할 시작점 X
		0,	// 복사할 시작점 Y
		(int)transform.scale.x, 			// 출력할 이미지의 크기 만큼 X
		(int)transform.scale.y,			// 출력할 이미지의 크기 만큼 Y
		RGB(255, 0, 255));		// 해당 색상을 제외

	/*
	Rectangle(hdc,
		int(transform.position.x - (transform.scale.x * 0.5f)),
		int(transform.position.y - (transform.scale.y * 0.5f)),
		int(transform.position.x + (transform.scale.x * 0.5f)),
		int(transform.position.y + (transform.scale.y * 0.5f)));
	*/
}

void Player::Destroy() {}


template <typename T>
GameObject* Player::CreateBullet(string _Key)
{
	GameObject* Obj = GET_SINGLE(ObjectPool)->GetGameObject(_Key);

	if (Obj == nullptr)
	{
		Bridge* pBridge = new T;
		pBridge->Start();
		((BulletBridge*)pBridge)->SetTarget(this);

		GameObject* ProtoObj = GET_SINGLE(Prototype)->GetGameObject("Bullet");

		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			Object->Start(transform.position);
			((BulletBridge*)pBridge)->ConnectObject(Object);

			return Object;
		}
		else
			return nullptr;
	}

	Obj->Start(transform.position);
	Obj->SetKey(_Key);

	return Obj;
}