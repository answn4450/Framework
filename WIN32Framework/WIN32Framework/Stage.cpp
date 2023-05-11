#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "SceneManager.h"


Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{
}

Stage::~Stage()
{
	Destroy();
}

void Stage::Start()
{
	m_pPlayer = new Player();
	m_pPlayer->Start();
	
	BulletList = GetSingle(ObjectManager)->GetObjectList("Bullet");
	EnemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");

	//ObjectManager::GetInstance()->AddObjectList(
		//(new Enemy)->Start());
}

void Stage::Update()
{
	list<GameObject*>* EnemyList = GetSingle(ObjectManager)->GetObjectList("Enemy");

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
			(*iter)->Update();
	}
	else
		BulletList = GetSingle(ObjectManager)->GetObjectList("Bullet");

	DWORD dwKey = GetSingle(InputManager)->GetKey();
	if (dwKey & KEYID_RIGHT)
	{
		//Sleep(100);
		//GetSingle(SceneManager)->SetScene(STAGE);
		GetSingle(SceneManager)->NextScene();
	}
}

void Stage::Render(HDC _hdc)
{
	if (m_pPlayer)
		m_pPlayer->Render(_hdc);

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
