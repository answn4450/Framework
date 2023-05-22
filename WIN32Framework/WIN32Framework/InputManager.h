#pragma once
#include "include.h"


class InputManager
{
public:
	SINGLE(InputManager)

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

