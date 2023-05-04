#pragma once
#include "Include.h";

class Stage
{
public:
	// PURE �� �� C3646 ���� �ɷ��� �ӽ� ��ü
	virtual void Start() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Destroy() = 0;

private:
	Stage();
public:
	~Stage();
};

