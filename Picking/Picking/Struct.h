#pragma once
typedef struct tagVector3
{
	float x, y, z;

	tagVector3() : x(0.0f), y(0.0f), z(0.0f) {}

	tagVector3(float _x, float _y) : x(_x), y(_y), z(0) {}

	tagVector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {}

	tagVector3 operator+(tagVector3 vector)
	{
		return Vector3(
			x + vector.x,
			y + vector.y,
			z + vector.z);
	}

	tagVector3 operator-(tagVector3 vector)
	{
		return Vector3(
			x - vector.x,
			y - vector.y,
			z - vector.z);
	}

	tagVector3 operator+=(tagVector3 vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;

		return Vector3(x, y, z);
	}

	tagVector3 operator-=(tagVector3 vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;

		return Vector3(x, y, z);
	}

	tagVector3 operator*(float value)
	{
		return Vector3(
			x * value,
			y * value,
			z * value);
	}


}Vector3;