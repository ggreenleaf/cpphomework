// lab1: simplegame_OOP
// Jose L. de Jesus
// read main.cpp, and follow the instructions at the bottom of main.cpp
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include "Entity.h"
#include "Vector2.h"
#include "Game.h"

#define ESCKEY 27

int main()
{
	//while (player.is_inbounds(WIDTH, HEIGHT) && !player.is_at_win_position(winX, winY))

	Game game;
	do 
	{
		game.draw();
		game.input = _getch();
		game.update();
	} while (game.get_game_state() == GameState::RUNNING);

	game.draw_endgame_message();
	std::cout << "Please press ESC to quit";
	while (_getch() != ESCKEY);
	return 0;
}