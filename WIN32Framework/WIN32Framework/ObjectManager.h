#pragma once

#include "Include.h"

class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == NULL)
			Instance = new ObjectManager;
		return Instance;
	}

private:
	map<string, list<GameObject*>> ObjectList[COUNT];
public:
	void AddObjectList(GameObject* _Object);
	list<GameObject*>* GetObjectList(string key);
private:
	ObjectManager();
public:
	~ObjectManager();
};


ObjectManager* ObjectManager::Instance = nullptr;