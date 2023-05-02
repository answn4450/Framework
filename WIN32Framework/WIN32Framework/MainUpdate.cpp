#include "MainUpdate.h"
#include "Player.h"

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

	rcPoint.left = 100;
	rcPoint.right = 200;

	rcPoint.top = 100;
	rcPoint.bottom = 200;
}

void MainUpdate::Update()
{
	m_pPlayer->Update();
}

void MainUpdate::Render()
{
	Rectangle(m_hdc,
		0, 0,
		1280, 720
	);

	Rectangle(m_hdc,
		rcPoint.left,
		rcPoint.top,
		rcPoint.right,
		rcPoint.bottom
	);
	m_pPlayer->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	delete m_pPlayer;
	m_pPlayer = NULL;
}
