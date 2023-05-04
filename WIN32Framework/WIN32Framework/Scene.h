#pragma once
#include "Include.h"

class Scene
{
public:
	// PURE �� �� C3646 ���� �ɷ��� �ӽ� ��ü

	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;

public:
	Scene();
	virtual ~Scene();
};

