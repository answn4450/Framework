#pragma once
#include "Include.h"

class Object
{
public:
	virtual void Start() PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	Object();
	virtual ~Object();
};

