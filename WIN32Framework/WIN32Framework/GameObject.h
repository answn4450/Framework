#pragma once
#include "include.h"

class GameObject
{
protected:
	Transform transform;
	//Vector3 vector
	int Speed;
	RECT rcPoint;

public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;
public:
	GameObject();
	~GameObject();
};