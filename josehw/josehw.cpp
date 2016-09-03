// lab1: simplegame_OOP
// Jose L. de Jesus
// read main.cpp, and follow the instructions at the bottom of main.cpp
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include "Entity.h"

#define ESC 27
#define WIDTH 20
#define HEIGHT 15

void move_cursor(int, int);
void draw_player(Entity&);
void draw_gameboard();
void show_message(std::string, int = HEIGHT); //will show message under game board

std::string get_endgame_message(Entity, int, int);

int main()
{
	Entity player(3, 4, 1);	//created with parameterized constructor 

	//Player.x = 3; - Commented out for step 1c
	//Player.y = 4;	- Commented out for step 1c
	//Player.icon = 1;	- Commented out for step 1c

	// game state constants
	//const int RUNNING = 1; 
	//const int WIN = 2;
	//const int LOST = 3; 
	//const int USER_QUIT = -1;
	char input;
	//int state = RUNNING;
	
	//Psuedocode for final game
	//while !notOutofBounds
	//	
	//	
	//	get input
	//	if esc 
	//		break
	//	move player
	//  draw board and player

	//	check win state
	//draw the initial board and player before entering main loop
	draw_gameboard();
	draw_player(player);
	int winX = 13;
	int winY = 10;

	while (player.is_inbounds(WIDTH, HEIGHT) && !player.is_at_win_position(winX, winY))
	{	
		input = _getch();
		if (input == ESC) 
		{
			break;
		}
		
		player.move_entity(input);
		draw_gameboard();
		draw_player(player);
	}
	
	std::string endGameMessage = get_endgame_message(player, winX, winY);
	show_message(endGameMessage);
	show_message("Press ESC to quit", HEIGHT + 2);
	while (_getch() != ESC);
	return 0;
}

void move_cursor(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_player(Entity &player)
{
	//since displaying the player moves the cursor we need to move it back under the player
	move_cursor(player.get_x(), player.get_y());
	player.show();
	move_cursor(player.get_x(), player.get_y());
}

void draw_gameboard()
{
	//before drawing board insure cursor is at top left.
	move_cursor(0, 0);
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			std::cout << '.';
		}
		std::cout << '\n';
	}
}

void show_message(std::string msg, int y)
{
	move_cursor(0, y + 1);
	std::cout << msg << std::endl;
}

std::string get_endgame_message(Entity player, int winX,int winY)
{
	std::string endGameMessage;
	if (!player.is_inbounds(WIDTH, HEIGHT))
	{
		endGameMessage = "You lose player out of bounds";
	}
	else if (player.is_at_win_position(winX, winY))
	{
		endGameMessage = "You Won!";
	}
	else
	{
		endGameMessage = "You quit the game early";
	}
	return endGameMessage;
}