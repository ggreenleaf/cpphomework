#include "stdafx.h"
#include "Vector2.h"

Vector2::Vector2():Vector2(0,0)
{
}

Vector2::Vector2(int x, int y) : x(x), y(y) 
{
}

bool Vector2::is(Vector2 v)
{
	return this->is(v.x, v.y);
}

bool Vector2::is(int a_x, int a_y)
{
	return this->x == a_x && this->y == a_y;
}

bool Vector2::operator==(Vector2 v)
{
	return this->is(v);
}