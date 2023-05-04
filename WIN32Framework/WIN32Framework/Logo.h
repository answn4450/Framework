#pragma once
#include "Include.h";
#include "SceneManager.h"

class Logo : public SceneManager
{
public:
	// PURE �� �� C3646 ���� �ɷ��� �ӽ� ��ü
	virtual void Start() override;
	virtual int Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Destroy() override;

public:
	Logo();
public:
	~Logo();
};

