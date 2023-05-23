#pragma once
#include "include.h"

class GameObject;
class ObjectPool
{
public:
	SINGLE(ObjectPool)

private:
	list<GameObject*> PoolList;

public:
	list<GameObject*>* GetList() { return &PoolList; }
	void ReturnObject(GameObject* _Object);

private:
	ObjectPool();
public:
	~ObjectPool();
};

