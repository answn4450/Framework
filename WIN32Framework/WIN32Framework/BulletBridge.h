#pragma once
#include "include.h"
#include "Bridge.h"

class BulletBridge:public Bridge
{
protected:
	GameObject* Target;
protected:
	float Speed;
public:
	virtual void Start()PURE;
	virtual void Update(Transform& transform)PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	void SetTarget(GameObject* _target) { Target = _target; }
public:
	BulletBridge() : Speed(0.0f), Target(nullptr) {}
	virtual ~BulletBridge() {}
};