#include "GameObject.h"

map<string, Bitmap*>* GameObject::m_ImageList = nullptr;


GameObject::GameObject() : Speed(0), pBridge(nullptr)
{
}

GameObject::~GameObject()
{
}