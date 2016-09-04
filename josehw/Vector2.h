#pragma once
struct Vector2
{
public:
	int x;
	int y;

public:
	Vector2();
	Vector2(int, int);
	bool operator== (Vector2);
	bool is (Vector2);
	bool is(int, int);
};

