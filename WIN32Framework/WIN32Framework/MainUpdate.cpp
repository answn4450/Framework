#include "MainUpdate.h"
#include "Player.h"
#include "Enemy.h"
#include "G_Enemy.h"

MainUpdate::MainUpdate() : m_pPlayer(NULL)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new Player();
	m_pPlayer->Start();

	m_pEnemy = new Enemy();
	GameObject* g_enemy = m_pEnemy;
	//int testNum = 3;

	m_pEnemy->Start();
}

void MainUpdate::Update()
{
	if (m_pPlayer)
		if (m_pEnemy)
			m_pPlayer->Update(m_pEnemy);
		else
		{
			m_pPlayer->Update();
		}

	if (m_pEnemy)
		m_pEnemy->Update();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, WIDTH, HEIGHT);

	if (m_pPlayer)
		m_pPlayer->Render(m_hdc);

	if (m_pEnemy)
		m_pEnemy->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (m_pEnemy)
	{
		delete m_pEnemy;
		m_pEnemy = NULL;
	}
}
