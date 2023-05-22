#pragma once

#include "Include.h"

class GameObject;
class ObjectManager
{
public:
	SINGLE(ObjectManager)

private:
	map<string, list<GameObject*>> ObjectList;
public:
	void AddObject(GameObject* _Object);
	list<GameObject*>* GetObjectList(string key);
private:
	ObjectManager();
public:
	~ObjectManager();
};