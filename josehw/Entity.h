#pragma once

class Entity 
{
	private:
		int x;
		int y;
		char icon;
	
	private:
		bool is_x_inbounds(int);
		bool is_y_inbounds(int);
	public:
		Entity(int, int, char);
		//getters
		int get_x() const;
		int get_y() const;
		char get_icon() const;

		//setters
		void set_x(int);
		void set_y(int);
		void set_icon(char);

		//methods
		void show() const;
		void move_entity(char);
		bool is_inbounds(int, int);
		bool is_at_win_position(int, int);
};
