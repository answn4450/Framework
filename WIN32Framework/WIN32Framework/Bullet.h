#pragma once
#include "GameObject.h"

class NormalBullet;
class Bullet : public GameObject
{
public:
	virtual GameObject* Start()override;
	virtual void Start(Vector3 _position)override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;
public:
	virtual GameObject* Clone() override
	{
		return new Bullet(*this);
	}
public:
	void Collide();
	Bullet();
	Bullet(Transform _transform) :GameObject(_transform) {}
	virtual ~Bullet();
};