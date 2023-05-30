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

void Player::SwitchAnimation(string _animName)
{
	if (_animName == "Idle")
	{
		frame.EndFrame = 7;
		frame.CountY = 0;
	}
	else if (_animName == "Run")
	{
		frame.EndFrame = 3;
		frame.CountY = 1;
	}
	else if (_animName == "Roll")
	{
		frame.EndFrame = 5;
		frame.CountY = 4;
	}else if (_animName == "Attack")
	{
		frame.EndFrame = 4;
		frame.CountY = 5;
	}
}

GameObject* Player::Start()
{
	frame.CountX = 0;
	frame.CountY = 0;
	frame.EndFrame = 7;
	frame.FrameTime = 50;
	transform.position = Vector3(WIDTH * 0.5f, HEIGHT *0.5f, 0.0f);
	transform.direction = Vector3(0.0f, 0.0f, 0.0f);
	transform.scale = Vector3(679/7, 639/9, 0.0f);

	Speed = 5.0f;

	Key = "Player";
	
	FlipX = false;
	Time = GetTickCount64();
	return this;
}


int Player::Update() {
	if (Time + frame.FrameTime < GetTickCount64())
	{
		Time = GetTickCount64();
		
		++frame.CountX;
		if (frame.CountX >= frame.EndFrame)
			frame.CountX = 0;
	}

	SwitchAnimation("Idle");
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
		SwitchAnimation("Run");
		FlipX = true;
	}

	if (dwKey & KEYID_RIGHT)
	{
		transform.position.x += 5.0f;
		SwitchAnimation("Run");
		FlipX = false;
	}

	if (dwKey & KEYID_SPACE)
	{
		GET_SINGLE(ObjectManager)->AddObject(CreateBullet<NormalBullet>("NormalBullet"));
		SwitchAnimation("Attack");
	}
	
	if (dwKey & KEYID_CONTROL)
	{
		GET_SINGLE(ObjectManager)->AddObject(CreateBullet<GuideBullet>("GuideBullet"));
		SwitchAnimation("Roll");
	}

	return 0;
}


void Player::Render(HDC hdc) {
	if (!FlipX)
	{
		TransparentBlt(hdc,	  // 복사해 넣을 그림판 ?!
			(int)transform.position.x,	// 복사할 영역 시작점 X
			(int)transform.position.y, 	// 복사할 영역 시작점 Y
			(int)transform.scale.x,	// 복사할 영역 끝부분 X
			(int)transform.scale.y, 	// 복사할 영역 끝부분 Y
			(*m_ImageList)["Player"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			transform.scale.x * frame.CountX,  // 복사할 시작점 X
			transform.scale.y * frame.CountY,	// 복사할 시작점 Y
			(int)transform.scale.x, 			// 출력할 이미지의 크기 만큼 X
			(int)transform.scale.y,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외
	}
	else
	{
		TransparentBlt(hdc,	  // 복사해 넣을 그림판 ?!
			(int)transform.position.x,	// 복사할 영역 시작점 X
			(int)transform.position.y, 	// 복사할 영역 시작점 Y
			(int)transform.scale.x,	// 복사할 영역 끝부분 X
			(int)transform.scale.y, 	// 복사할 영역 끝부분 Y
			(*m_ImageList)["PlayerFlipX"]->GetMemDC(),	// 복사할 이미지 (복사대상)
			transform.scale.x * (6-frame.CountX),  // 복사할 시작점 X
			transform.scale.y * frame.CountY,	// 복사할 시작점 Y
			(int)transform.scale.x, 			// 출력할 이미지의 크기 만큼 X
			(int)transform.scale.y,			// 출력할 이미지의 크기 만큼 Y
			RGB(255, 0, 255));		// 해당 색상을 제외
	}

	/*
	StretchBlt(hdc,
	// 좌우 반전 됐음.
		(int)transform.position.x,
		(int)transform.position.y, 
		-(int)transform.scale.x,
		(int)transform.scale.y,
		(*m_ImageList)[Key]->GetMemDC(),	
		transform.scale.x * frame.CountX,
		0,
		(int)transform.scale.x, 
		(int)transform.scale.y,
		SRCCOPY
		);
	*/

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