#include "ObjectPool.h"
#include "GameObject.h"

void ObjectPool::ReturnObject(GameObject* _Object)
{
	map<string, list<GameObject*>>::iterator iter = PoolList.find(_Object->GetKey());
	// ** 만약 키가 없다면....
	if (iter == PoolList.end())
	{
		// ** map에 포함시킬 list를 생성한후...
		list<GameObject*> tempList;

		// ** 리스트에 오브젝트를 추가
		tempList.push_back(_Object);

		// ** 오브젝트가 추가된 리스트를 map에 추가
		PoolList.insert(make_pair(_Object->GetKey(), tempList));
	}
	else // ** 이미 키가 존재한다면...
		// ** 해당 리스트에 오브젝트를 추가
		iter->second.push_back(_Object);
}

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}