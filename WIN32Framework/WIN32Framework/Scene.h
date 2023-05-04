#pragma once
#include "Include.h"

class Scene
{
public:
	// PURE 쓸 때 C3646 에러 걸려서 임시 대체

	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;

public:
	Scene();
	virtual ~Scene();
};

