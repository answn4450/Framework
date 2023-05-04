#pragma once
#include "Include.h";

class Menu
{
public:
	// PURE �� �� C3646 ���� �ɷ��� �ӽ� ��ü
	virtual void Start() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;

private:
	Menu();
public:
	~Menu();
};

