#pragma once
#include "Include.h"

class GameObject
{
protected:
	Transform transform;
	float Speed;

public:
	virtual void Start()PURE;
	virtual void Start(Vector3 _position)PURE;
	virtual int Update()PURE;
	virtual void Update(GameObject* _collision)PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	Transform GetTransform() { return transform; }
	//void SetTransform() { return transform; }
	Vector3 GetPosition() { return transform.position; }
	void SetPosition(Vector3 _position) { transform.position = _position; }
public:
	GameObject();
	virtual ~GameObject();
};