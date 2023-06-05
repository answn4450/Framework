#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <string>
#include <Windows.h>
#include <math.h>

using namespace std;


#include "Struct.h"
#include "Enum.h"


// ** �̹���
#pragma comment(lib, "msimg32.lib")


#define Single(T)					\
public:								\
	static T** GetInstance()		\
	{								\
		static T* instance;			\
		if(instance == nullptr)		\
			instance = new T;		\
		return &instance;			\
	}								\
private:							\
	T(const T&) = delete;			\
	T& operator=(const T&) = delete;

#define GetSingle(T) (*T::GetInstance())

// ** Ÿ�� ����, ���� ũ��
#define WIDTH	1280
#define HEIGHT	720

// ** Ÿ�� ����, ���� ũ��
#define SCALE_X 32.0f
#define SCALE_Y 32.0f

// ** Ÿ�� ����, ���� �ִ� ����
#define COUNT_X (WIDTH/SCALE_X)
#define COUNT_Y (HEIGHT/SCALE_Y)




// ** Ÿ�� �ִ� ����
const int MAX = COUNT_X * COUNT_Y;


extern HWND g_hWnd;


template <typename T>
inline void Safe_Release(T& _Object)
{
	if (_Object)
	{
		delete _Object;
		_Object = nullptr;
	}
}