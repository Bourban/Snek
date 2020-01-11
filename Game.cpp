#include "Game.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>

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
	std::getline(std::cin, input);
	inputChar = input[0];
	inputChar = std::tolower(inputChar);

}

void Game::update()
{
	updatePlayer(inputChar);
	updateMap();
}

void Game::draw()
{
	system("CLS");

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

	player.reserve(MAP_HEIGHT * MAP_WIDTH);

	player.emplace_back(point(7, 7));
	player.emplace_back(point(7, 8));
	player.emplace_back(point(7, 9));
	updateMap();
}

void Game::updatePlayer(char input)
{

	int tx, ty;

	switch (input)
	{
	case 'w':
		//passing by reference here because I'm changing the values
		for (std::vector<int>::size_type i = player.size() - 1; i != (std::vector<int>::size_type) - 2; i--)
		{
			player[i] = player[i - 1];
		}
		player[0].y--;

		break;
	case 'a':
		for (std::vector<point>::reverse_iterator it = player.rbegin(); it != player.rend(); ++it) 
		{
			tx = it->x;
		}

		break;
	case 's':
		
		for (auto p : player) 
		{
			tx = p.x;
			ty = p.y;
		}
	
		break;
	case 'd':
		for (auto i = player.end(); i != player.begin(); i--)
		{
			if (i != player.begin())
			{
				i = i - 1;
			}
			else {
				i->x++;
			}
		}
		break;

	default:
		break;
	}

	for (auto &p : player)
	{
		p.x = p.x % MAP_WIDTH;
		p.y = p.y % MAP_HEIGHT;

		if (p.x < 0)
			p.x = MAP_WIDTH - 1;
		if (p.y < 0)
			p.y = MAP_HEIGHT - 1;
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
