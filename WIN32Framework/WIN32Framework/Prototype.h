#pragma once
#include "include.h"


class GameObject;
class Prototype
{
public:
	SINGLE(Prototype)
private:
	map<string, GameObject*> PrototypeObject;
public:
	void Start();
	GameObject* GetGameObject(string _key);
private:
	Prototype();
public:
	~Prototype();
};

