#pragma once

#include "Include.h"

class GameObject;
class ObjectManager
{
public:
	Single(ObjectManager)

private:
	map<string, list<GameObject*>> ObjectList;
public:
	void AddObjectList(GameObject* _Object);
	list<GameObject*>* GetObjectList(string key);
private:
	ObjectManager();
public:
	~ObjectManager();
};