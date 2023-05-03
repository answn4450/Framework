#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
	GameObject* bulletList[BULLETCOUNT];
public:
	virtual void Start();
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Destroy();
public:
	GameObject* CreateBullet();

public:
	Player();
	~Player();
};