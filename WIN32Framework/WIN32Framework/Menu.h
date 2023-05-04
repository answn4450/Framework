#pragma once
#include "Include.h";

class Menu
{
public:
	// PURE 쓸 때 C3646 에러 걸려서 임시 대체
	virtual void Start() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;

private:
	Menu();
public:
	~Menu();
};

