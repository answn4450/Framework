#include "ObjectPool.h"

void ObjectPool::ReturnObject(GameObject* _Object)
{
	PoolList.push_back(_Object);
}

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}