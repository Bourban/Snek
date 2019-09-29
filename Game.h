#pragma once
#include <vector>

struct point
{
	int x;
	int y;

	point(int x, int y) : x(x), y(y)
	{
		
	}

};

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	void getInput();
	void update();
	void draw();
	void initialise();

	void updatePlayer(char input);
	void updateMap();

private:
	bool bPlaying;

	static const int MAP_HEIGHT = 15;
	static const int MAP_WIDTH = 15;

	char map[MAP_WIDTH][MAP_HEIGHT];

	char input;

	int iPlayerHeadIndex;

	std::vector<point> player;
};

