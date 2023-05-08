#pragma once
#include "Scene.h"

class GameObject;
class Stage : public Scene
{
private:
	GameObject* m_pPlayer;
	list<GameObject*>* BulletList;
	list<GameObject*>* EnemyList;

public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render(HDC hdc)override;
	virtual void Destroy()override;

public:
	Stage();
	virtual ~Stage();
};

