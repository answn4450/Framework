#include "ObjectManager.h"
#include "GameObject.h"


void ObjectManager::AddObjectList(GameObject* _Object)
{
	map<string, list<GameObject*>>::iterator iter = ObjectList->find(_Object->GetKey());

	if (iter == ObjectList->end())
	{
		list<GameObject*> tempList;
		tempList.push_back(_Object);

		ObjectList->insert(make_pair(_Object->GetKey(), tempList));
	}
	else
		iter->second.push_back(_Object);
}

list<GameObject*>* ObjectManager::GetObjectList(string key)
{
	map<string, list<GameObject*>>::iterator iter = ObjectList->find(key);

	if (iter == (ObjectList->end()))
		return nullptr;
	else
		return &iter->second;
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}
