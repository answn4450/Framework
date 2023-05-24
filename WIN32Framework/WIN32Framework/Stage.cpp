#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "Prototype.h"


Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	GET_SINGLE(Prototype)->Start();

	{
		GameObject* ProtoObj = GET_SINGLE(Prototype)->GetGameObject("Player");
		if (ProtoObj != nullptr)
		{
			m_pPlayer = ProtoObj->Clone();
			m_pPlayer->Start();
		}
	}

	{
		GameObject* ProtoObj = GET_SINGLE(Prototype)->GetGameObject("Enemy");
		if (ProtoObj != nullptr)
		{
			GameObject* Object = ProtoObj->Clone();
			GET_SINGLE(ObjectManager)->AddObject(Object);
		}
	}

	GET_SINGLE(ObjectManager)->AddObject(
		(new Enemy)->Start()
	);

	BulletList = GET_SINGLE(ObjectManager)->GetObjectList("Bullet");
	EnemyList = GET_SINGLE(ObjectManager)->GetObjectList("Enemy");
}

void Stage::Update()
{
	list<GameObject*>* EnemyList = GET_SINGLE(ObjectManager)->GetObjectList("Enemy");

	if (m_pPlayer)
		m_pPlayer->Update();

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Update();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			(*iter)->Update();
		}
	}
	else
		BulletList = GET_SINGLE(ObjectManager)->GetObjectList("Bullet");

	// Enemy¿Í Bullet
	if (EnemyList != nullptr && !EnemyList->empty()
		&& BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iterEnemy = EnemyList->begin(); iterEnemy != EnemyList->end(); ++iterEnemy)
		{
			for (list<GameObject*>::iterator iterBullet = BulletList->begin(); iterBullet != BulletList->end(); ++iterBullet)
			{
				if (CollisionManager::Collision(*iterBullet, *iterEnemy))
				{
					(*iterBullet)->Destroy();
				}
			}
		}
	}
}

void Stage::Render(HDC _hdc)
{
	if (m_pPlayer)
		m_pPlayer->Render(_hdc);

	/*
	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Render(_hdc);
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Render(_hdc);
	}
	*/
	GET_SINGLE(ObjectManager)->Render(_hdc);
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (EnemyList != nullptr && !EnemyList->empty())
	{
		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		EnemyList->clear();
	}

	if (BulletList != nullptr && !BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		BulletList->clear();
	}
}
