#pragma once
#include "Include.h";
#include "SceneManager.h"

class Logo : public SceneManager
{
public:
	// PURE 쓸 때 C3646 에러 걸려서 임시 대체
	virtual void Start() override;
	virtual int Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Destroy() override;

public:
	Logo();
public:
	~Logo();
};

