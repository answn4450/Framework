#include "Prototype.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


Prototype::Prototype()
{
}

Prototype::~Prototype()
{
}

void Prototype::Start()
{
	Transform transform;

	transform.position = Vector3(0.0f ,0.0f, 0.0f);
	transform.direction = Vector3(0.0f ,0.0f, 0.0f);
	transform.scale = Vector3(0.0f ,0.0f, 0.0f);

	string Key = "Player";
	PrototypeObject.insert(make_pair(Key, (new Player(transform))->Start()->SetKey(Key)));

	Key = "Bullet";
	PrototypeObject.insert(make_pair(Key, (new Bullet(transform))->Start()->SetKey(Key)));

	Key = "NormalBullet";
	PrototypeObject.insert(make_pair(Key, (new Bullet(transform))->Start()->SetKey(Key)));

	Key = "GuideBullet";
	PrototypeObject.insert(make_pair(Key, (new Bullet(transform))->Start()->SetKey(Key)));

	Key = "Enemy";
	PrototypeObject.insert(make_pair(Key, (new Enemy(transform))->Start()->SetKey(Key)));
}

GameObject* Prototype::GetGameObject(string _key)
{
	map<string, GameObject*>::iterator iter = PrototypeObject.find(_key);

	if (iter == PrototypeObject.end())
		return nullptr;
	else
		return iter->second;
}

