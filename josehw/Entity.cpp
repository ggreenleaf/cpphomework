#include "stdafx.h"
#include "Entity.h"
#include <iostream>

Entity::Entity(int x, int y, char icon)
{
	this->x = x;
	this->y = y;
	this->icon = icon;
}

void Entity::set_x(int x) 
{
	this->x = x;
}

void Entity::set_y(int y)
{
	this->y = y;
}

void Entity::set_icon(char icon) 
{
	this->icon = icon;
}

int Entity::get_x() const
{
	return this->x;
}

int Entity::get_y() const
{
	return this->y;
}

char Entity::get_icon() const
{
	return this->icon;
}

void Entity::show() const
{
	std::cout << get_icon();
}

void Entity::move_entity(char input)
{
	//doesnt have bound checking
	switch (input)
	{
		case 'w':
			set_y(this->y - 1);
			break;
		case 'd':
			set_x(this->x + 1);
			break;
		case 's':
			set_y(this->y + 1);
			break;
		case 'a':
			set_x(this->x - 1);
			break;
		default:
			break;
	}
}

bool Entity::is_inbounds(int width, int height)
{
	return (is_x_inbounds(width) && is_y_inbounds(height));
}

bool Entity::is_x_inbounds(int width)
{
	return (this->x >= 0 && this->x < width);
}
bool Entity::is_y_inbounds(int height)
{
	return (this->y >= 0 && this->y < height);
}

bool Entity::is_at_win_position(int winX, int winY)
{
	return (this->x == winX && this->y == winY);
}