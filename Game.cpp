#include "Game.h"
#include <iostream>
#include <cctype>

Game::Game()
{
}


Game::~Game()
{
}

void Game::run()
{
	initialise();

	while (bPlaying)
	{
		draw();
		getInput();
		update();

	}
}

void Game::getInput()
{
	std::cin >> input;
	input = std::tolower(input);

}

void Game::update()
{
	updatePlayer(input);
	updateMap();
}

void Game::draw()
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			//Need to draw this as[j][i] or the coordinate system will be skewed 90 degrees
			std::cout << map[j][i] << ' ';
		}
		std::cout << "\n";
	}
}

void Game::initialise()
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			map[i][j] = '-';
		}
	}

	bPlaying = true;

	player.push_back(point(7, 7));
	updateMap();
}

void Game::updatePlayer(char input)
{

	switch (input)
	{
	case 'w':
		//passing by reference here because I'm changing the values
		for (auto &p : player)
		{
			p.y--;
			p.y = p.y % MAP_WIDTH;
			std::cout << p.y << "\n";
		}
		break;
	case 'a':
		for (auto &p : player)
		{
			p.x--;
		}
		break;
	case 's':
		for (auto &p : player)
		{
			p.y++;
		}
		break;
	case 'd':
		for (auto &p : player)
		{
			p.x++;
		}
		break;

	default:
		break;
	}

}

void Game::updateMap()
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			map[i][j] = '-';
		}
	}

	for (auto p : player)
	{
		map[p.x][p.y] = 'o';
	}
	//Making sure the first element is always a capital O to denote the head
	map[player[0].x][player[0].y] = 'O';
}
