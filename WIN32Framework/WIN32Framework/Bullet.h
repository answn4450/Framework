#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{/*
private:
	RECT rcPoint;
	GameObject* m_pPlayer;
 */
public:
	virtual void Start()override;
	//virtual void Start(Vector3 _position)override;
	virtual int Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;

public:
	void Collide();
	Bullet();
	virtual ~Bullet();
};