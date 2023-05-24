#include "ObjectPool.h"
#include "GameObject.h"

void ObjectPool::ReturnObject(GameObject* _Object)
{
	map<string, list<GameObject*>>::iterator iter = PoolList.find(_Object->GetKey());
	// ** ���� Ű�� ���ٸ�....
	if (iter == PoolList.end())
	{
		// ** map�� ���Խ�ų list�� ��������...
		list<GameObject*> tempList;

		// ** ����Ʈ�� ������Ʈ�� �߰�
		tempList.push_back(_Object);

		// ** ������Ʈ�� �߰��� ����Ʈ�� map�� �߰�
		PoolList.insert(make_pair(_Object->GetKey(), tempList));
	}
	else // ** �̹� Ű�� �����Ѵٸ�...
		// ** �ش� ����Ʈ�� ������Ʈ�� �߰�
		iter->second.push_back(_Object);
}

ObjectPool::ObjectPool()
{
}

ObjectPool::~ObjectPool()
{
}