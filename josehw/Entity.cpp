#include "stdafx.h"
#include "Entity.h"
#include <iostream>

Entity::Entity(int x, int y, char icon)
{
	this->pos = Vector2(x, y);
	this->icon = icon;
}
Entity::Entity(Vector2 v, char icon) : pos(v), icon(icon)
{}

Entity::Entity()
{
	this->pos = Vector2(0, 0);
	this->icon = 1;
}
char Entity::get_icon()
{
	return icon;
}
Vector2 Entity::get_pos()
{
	return this->pos;
}

void Entity::set_pos(int x, int y)
{
	set_pos_x(x);
	set_pos_y(y);
}
void Entity::set_pos(Vector2 v)
{
	this->pos = v;
}

void Entity::set_pos_x(int x)
{
	this->pos.x = x;
}
void Entity::set_pos_y(int y)
{
	this->pos.y = y;
}

void Entity::show() const
{
	std::cout << this->icon;
}

void Entity::move_entity(char input)
{
	//doesnt have bound checking
	switch (input)
	{
		case UP:
			this->pos.y -= 1;
			break;
		case RIGHT:
			this->pos.x += 1;
			break;
		case DOWN:
			this->pos.y += 1;
			break;
		case LEFT:
			this->pos.x -= 1;
			break;
		default:
			break;
	}
}