#pragma once
#include "Include.h"
#include "Bridge.h"

class Bitmap;
class GameObject
{
protected:
	Transform transform;
	float Speed;
	string Key;

	ULONGLONG Time;
	Frame frame;
	Bridge* pBridge;
	static map<string, Bitmap*>* m_ImageList;
public:
	static void SetImageList(map<string, Bitmap*>* _ImageList) { m_ImageList = _ImageList; }
public:
	virtual GameObject* Start()PURE;
	virtual void Start(Vector3 _position)PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	virtual GameObject* Clone()PURE;
public:
	Transform GetTransform() const { return transform; }
	
	Vector3 GetPosition() const { return transform.position; }
	void SetPosition(Vector3 _position) { transform.position = _position;}
	
	Vector3 GetRotation() const { return transform.direction; }
	void SetRotation(Vector3 _direction) { transform.direction = _direction; }
	
	Vector3 GetScale() const { return transform.scale; }
	void SetScale(Vector3 _scale) { transform.scale = _scale; }
	
	string GetKey() const { return Key; }

	// 나중에 삭제할 예정
	GameObject* SetKey(const string _key)
	{
		Key = _key;
		return this;
	}

	void SetBridge(Bridge* _bridge) { pBridge = _bridge; }
public:
	GameObject();
	GameObject(Transform _transform) : transform(_transform), Speed(0.0f), pBridge(nullptr) {}
	virtual ~GameObject();
};