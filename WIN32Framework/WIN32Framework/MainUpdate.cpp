#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"


MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}

void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	GET_SINGLE(SceneManager)->SetScene(LOGO);
}

void MainUpdate::Update()
{
	GET_SINGLE(InputManager)->CheckKey();
	GET_SINGLE(SceneManager)->Update();
}

void MainUpdate::Render()
{
	//Rectangle(m_hdc, 0, 0, WIDTH, HEIGHT);
	GET_SINGLE(SceneManager)->Render(m_hdc);
}

void MainUpdate::Destroy()
{
	GET_SINGLE(SceneManager)->Destroy();
}