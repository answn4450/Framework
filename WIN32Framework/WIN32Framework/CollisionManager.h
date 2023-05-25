#pragma once
#include "Include.h"
#include "GameObject.h"

class CollisionManager
{
public:
	// ** 구(동그라미) 충돌
	static bool Collision(GameObject* temp, GameObject *dest)
	{
		// ** x값과 y값을 구한다. 
		float fx = dest->GetPosition().x - temp->GetPosition().x;
		float fy = dest->GetPosition().y - temp->GetPosition().y;
		
		// ** 각각의 구의 반지름의 합을 구함.
		float sum = (dest->GetScale().x + temp->GetScale().x) * 0.5f;

		// ** 거리를 구함.
		float distance = sqrt((fx * fx) + (fy * fy));

		// ** 거리가 반지름의 합보다 작다면 충돌..
		if (distance < sum)
			return true;

		return false;
	}

	/*
	// ** Rect 충돌
	static bool Collision(GameObject* temp, GameObject* dest)
	{
		//if (abs(temp->GetPosition().x- dest->GetPosition().x)< temp->GetScale().x+ dest->GetScale().x)
		if (temp->GetPosition().x + (temp->GetScale().x * 0.5f) > dest->GetPosition().x - (dest->GetScale().x * 0.5f) &&
			dest->GetPosition().x + (dest->GetScale().x * 0.5f) < temp->GetPosition().x - (temp->GetScale().x * 0.5f) &&
			temp->GetPosition().y + (temp->GetScale().y * 0.5f) > dest->GetPosition().y - (dest->GetScale().y * 0.5f) &&
			dest->GetPosition().y + (dest->GetScale().y * 0.5f) < temp->GetPosition().y - (temp->GetScale().y * 0.5f)
			)
		{
			return true;
		}
		return false;
	}
	*/
};