#pragma once
#include "GameObject.h"


class Player : public GameObject
{
private:
	void SwitchAnimation(string _animName);
	bool FlipX;
public:
	virtual GameObject* Start();
	virtual void Start(Vector3 _position)override
	{

	}
	virtual int Update();
	virtual void Render(HDC hdc);
	virtual void Destroy();
public:
	virtual GameObject* Clone() override
	{
		return new Player(*this);
	}
public:
	template <typename T>
	GameObject* CreateBullet(string _Key);

public:
	Player();
	Player(Transform _transform) :GameObject(_transform) {}
	~Player();
};