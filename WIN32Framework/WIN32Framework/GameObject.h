#pragma once
#include "Include.h"

class GameObject
{
protected:
	Transform transform;
	float Speed;

	string Key;
public:
	// PURE 쓸 때 C3646 에러 걸려서 임시 대체
	virtual GameObject* Start()PURE;
	virtual void Start(Vector3 _position)PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	Transform GetTransform() const { return transform; }
	
	Vector3 GetPosition() const { return transform.position; }
	void SetPosition(Vector3 _position) { transform.position = _position;}
	
	Vector3 GetRotation() const { return transform.direction; }
	void SetRotation(Vector3 _direction) { transform.direction = _direction; }
	
	Vector3 GetScale() const { return transform.scale; }
	void SetScale(Vector3 _scale) { transform.scale = _scale; }
	
	string GetKey() const { return Key; }
public:
	GameObject();
	virtual ~GameObject();
};