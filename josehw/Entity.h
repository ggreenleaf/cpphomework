#pragma once
#include "Vector2.h"

enum Movement {UP, LEFT, DOWN, RIGHT};

class Entity 
{
	private:
		Vector2 pos;
		char icon;
	
	private:
		void set_pos_x(int);
		void set_pos_y(int);

	public:
		Entity(int, int, char);
		Entity(Vector2, char);
		Entity();
		//getters
		Vector2 get_pos();
		void set_pos(int,int);
		void set_pos(Vector2);
		char get_icon();
		//methods
		void show() const;
		void move_entity(char);
};
