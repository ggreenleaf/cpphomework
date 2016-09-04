#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <Windows.h>
//Game::Game(Entity player, Entity nemesis, Entity winPosition, Vector2 gameboard)
//{
//}
#define ESC 27

Game::Game()
{
	//default game creation will match hw defaults
	player = Entity(Vector2(3, 4), 1);
	nemesis = Entity(Vector2(7, 7), 2);
	gameboard = Vector2(20, 15);
	this->winPosition = Entity(Vector2(gameboard.x / 2, gameboard.y / 2), 'W');
	state = RUNNING;
}

Game::Game(Entity player, Entity nemesis, Entity winPosition, Vector2 gameboard) :
	player(player), nemesis(nemesis), winPosition(winPosition), gameboard(gameboard)
{
	state = RUNNING;
}
void Game::draw_gameboard()
{
	move_cursor(Vector2(0,0));
	for (int i = 0; i < gameboard.y; i++)
	{
		for (int j = 0; j < gameboard.x; j++)
		{
			std::cout << '.';
		}
		std::cout << std::endl;
	}
}

void Game::move_cursor(Vector2 v)
{
	COORD c = { v.x, v.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Game::draw_player_and_nemesis()
{
	draw_nemesis();
	draw_player();
}

void Game::draw_player()
{
	move_cursor(player.get_pos());
	player.show();
	move_cursor(player.get_pos());
}

void Game::draw_nemesis()
{
	move_cursor(nemesis.get_pos());
	nemesis.show();
	move_cursor(nemesis.get_pos());
}

void Game::draw_win_position()
{
	move_cursor(winPosition.get_pos());
	winPosition.show();
	move_cursor(winPosition.get_pos());
}

bool Game::is_player_inbounds()
{
	bool isXInBounds = player.get_pos().x >= 0 && player.get_pos().x < gameboard.x;
	bool isYInBounds = player.get_pos().y >= 0 && player.get_pos().y < gameboard.y;
	move_cursor(Vector2(0, gameboard.y + 1));

	return isXInBounds && isYInBounds;
}

bool Game::is_player_at_win_position()
{
	return player.get_pos() == winPosition.get_pos();
}

void Game::set_game_state()
{
	if (!is_player_inbounds() || player.get_pos() == nemesis.get_pos())
	{
		state = LOST;
	}
	else if (is_player_at_win_position())
	{
		state = WIN;
	}
	else if (input == ESC)
	{
		state = USER_QUIT;
	}
	else 
	{
		state = RUNNING;
	}
}

void Game::move_player()
{
	switch (input)
	{
	case 'w':
		player.move_entity(Movement::UP);
		break;
	case 'd':
		player.move_entity(Movement::RIGHT);
		break;
	case 's':
		player.move_entity(Movement::DOWN);
		break;
	case 'a':
		player.move_entity(Movement::LEFT);
		break;
	}
}

void Game::move_nemesis()
{
	switch (input)
	{
		case 'i':
			nemesis.move_entity(Movement::UP);
			break;
		case 'l':
			nemesis.move_entity(Movement::RIGHT);
			break;
		case 'k':
			nemesis.move_entity(Movement::DOWN);
			break;
		case 'j':
			nemesis.move_entity(Movement::LEFT);
			break;

	}
}

GameState Game::get_game_state()
{
	return state;
}
void Game::draw_endgame_message()
{
	Vector2 messageLocation(0, gameboard.y + +1);
	move_cursor(messageLocation);
	switch (state)
	{
	case GameState::WIN:
		std::cout << "You won!";
		break;
	case GameState::LOST:
		std::cout << "You Lost!";
		break;
	case GameState::USER_QUIT:
		std::cout << "You Quit!";
		break;
	default:
		break;
	}
	std::cout << std::endl;
}
void Game::update()
{
	move_player();
	move_nemesis();
	set_game_state();
}

void Game::draw()
{
	draw_gameboard();
	draw_player_and_nemesis();
	draw_win_position();
}