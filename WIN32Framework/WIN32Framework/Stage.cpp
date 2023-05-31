#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"
#include "Prototype.h"
#include "ObjectPool.h"

#include "ImageManager.h"
#include "Bitmap.h"

#include <tchar.h>

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
			GameObject* Object = ProtoObj->Clone()->Start();
			GET_SINGLE(ObjectManager)->AddObject(Object);
		}
	}

	EnemyList = GET_SINGLE(ObjectManager)->GetObjectList("Enemy");
	//map<string, Bitmap*>* 
	m_mapImageList = GET_SINGLE(ImageManager)->GetImageList();


	(*m_mapImageList)["BackGround"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/BackGround.bmp");
	(*m_mapImageList)["Buffer"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/Buffer.bmp");
	(*m_mapImageList)["PlayerL"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/Player_L.bmp");
	(*m_mapImageList)["PlayerR"] = (new Bitmap)->LoadBmp(L"../Resource/Stage/Player_R.bmp");
	GameObject::SetImageList(m_mapImageList);
}

void Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	GET_SINGLE(ObjectManager)->Update();
}

void Stage::Render(HDC _hdc)
{
	BitBlt((*m_mapImageList)["Buffer"]->GetMemDC(),			// ������ ���� �׸��� ?!
		0, 0, WIDTH, HEIGHT,		// ������ ���� ���������κ��� ���κб���
		(*m_mapImageList)["BackGround"]->GetMemDC(),		// ������ �̹���
		0, 0,				// �������� ����ش�.
		SRCCOPY);			// �ҽ� ������ ��� ������ �����Ѵ�.

	if (m_pPlayer)
		m_pPlayer->Render(
			(*m_mapImageList)["Buffer"]->GetMemDC());

	GET_SINGLE(ObjectManager)->Render(
		(*m_mapImageList)["Buffer"]->GetMemDC());

	BitBlt(_hdc,			// ������ ���� �׸��� ?!
		0, 0, WIDTH, HEIGHT,		// ������ ���� ���������κ��� ���κб���
		(*m_mapImageList)["Buffer"]->GetMemDC(),		// ������ �̹���
		0, 0,				// �������� ����ش�.
		SRCCOPY);			// �ҽ� ������ ��� ������ �����Ѵ�.

#if DEBUG
	list<GameObject*>* normalList = GET_SINGLE(ObjectManager)->GetObjectList("NormalBullet");
	list<GameObject*>* enemyList = GET_SINGLE(ObjectManager)->GetObjectList("Enemy");
	list<GameObject*>* guideList = GET_SINGLE(ObjectManager)->GetObjectList("GuideBullet");

	if (normalList != nullptr && !normalList->empty())
	{
		// ** Buffer ����
		// ** �迭�� ���̴� �߿����� ����. (����ϸ� ��.)
		char* NormalBuffer = new char[1024];

		// ** ������ ���ڿ��� ��ȯ. 10������ ��ȯ��.
		_itoa((int)normalList->size(), NormalBuffer, 10);

		// ** ���ڿ� �����͸� string ���� ��ȯ.
		string str(NormalBuffer);

		// ** ���ڿ� ������ ��ü ����.
		delete[] NormalBuffer;
		NormalBuffer = nullptr;

		// ** �����ڵ� ���·� ����.
		wchar_t* t = new wchar_t[(int)str.size()];
		
		// ** ���ڿ� ����.
		mbstowcs(t, str.c_str(), (int)str.size());
		
		// ** ���
		TextOut(_hdc, 50, 50, (LPCWSTR)t, (int)str.size());
	}

	if (guideList != nullptr && !guideList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa(guideList->size(), GuideBuffer, 10);

		string str(GuideBuffer);

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		TextOut(_hdc, 50, 70, (LPCWSTR)t, (int)str.size());
	}

	if (enemyList != nullptr && !enemyList->empty())
	{
		char* EnemyBuffer = new char[128];
		_itoa((int)enemyList->size(), EnemyBuffer, 10);

		string str(EnemyBuffer);

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		delete[] EnemyBuffer;
		EnemyBuffer = nullptr;

		TextOut(_hdc, 50, 90, (LPCWSTR)t, (int)str.size());
	}

	list<GameObject*>* NormalBulletList = GET_SINGLE(ObjectPool)->GetList("NormalBullet");
	list<GameObject*>* GuideBulletList = GET_SINGLE(ObjectPool)->GetList("GuideBullet");

	if (NormalBulletList != nullptr && !NormalBulletList->empty())
	{
		char* normalBuffer = new char[128];
		_itoa((int)NormalBulletList->size(), normalBuffer, 10);

		string str(normalBuffer);

		delete[] normalBuffer;
		normalBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		TextOut(_hdc, 120, 50, (LPCWSTR)t, (int)str.size());
	}

	if (GuideBulletList != nullptr && !GuideBulletList->empty())
	{
		char* GuideBuffer = new char[128];
		_itoa((int)GuideBulletList->size(), GuideBuffer, 10);

		string str(GuideBuffer);

		delete[] GuideBuffer;
		GuideBuffer = nullptr;

		wchar_t* t = new wchar_t[(int)str.size()];
		mbstowcs(t, str.c_str(), (int)str.size());

		TextOut(_hdc, 120, 70, (LPCWSTR)t, (int)str.size());
	}
#endif //DEBUG
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
