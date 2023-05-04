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
	virtual GameObject* Start() = 0;
	virtual void Start(Vector3 _position) = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;
public:
	Transform GetTransform() { return transform; }
	//void SetTransform() { return transform; }
	Vector3 GetPosition() { return transform.position; }
	void SetPosition(Vector3 _position) { transform.position = _position;}
	Vector3 GetRotation() { return transform.rotation; }
	void SetRotation(Vector3 _rotation) { transform.rotation = _rotation; }
	Vector3 GetScale() { return transform.scale; }
	void SetScale(Vector3 _scale) { transform.scale = _scale; }
	string GetKey() { return Key; }
public:
	GameObject();
	virtual ~GameObject();
};