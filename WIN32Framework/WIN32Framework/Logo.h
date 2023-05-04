#pragma once
#include "Scene.h"

class Logo : public Scene
{
public:
	virtual void Start() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Destroy() override;

public:
	Logo();
	virtual ~Logo();
};

