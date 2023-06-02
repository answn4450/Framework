#pragma once
#include "Include.h"

class Bitmap;
class Object;
class Stage
{
private:
	Bitmap* background;
	Object* object;
public:
	void Start();
	int Update();
	void Render(HDC hdc);
	void Destroy();
public:
	Stage();
	virtual ~Stage();
};

