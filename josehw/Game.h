#pragma once
#include "Entity.h"

enum GameState { RUNNING, WIN, LOST, USER_QUIT };

class Game
{
private:
	Entity player;
	Entity winPosition;
	Entity nemesis;
	Vector2 gameboard;
	GameState state;

public:
	char input;

private:
	void move_cursor(Vector2);
	void draw_player();
	void draw_nemesis();
	void draw_player_and_nemesis();
	void draw_win_position();
	void set_game_state();
	bool is_player_at_win_position();
	bool is_player_inbounds();
	void move_player();
	void move_nemesis();


public:
	
	Game();
	Game(Entity, Entity, Entity, Vector2);
	void draw_gameboard();
	void draw();
	void update();
	void draw_endgame_message();
	GameState get_game_state();
};

