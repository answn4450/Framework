#pragma once
#include "include.h"


class InputManager
{
private:
	static InputManager* Instance;
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}

public:
	DWORD GetKey() { return inputKey; }
	void CheckKey();
private:
	DWORD inputKey;

private:
	InputManager();
public:
	~InputManager();
};

