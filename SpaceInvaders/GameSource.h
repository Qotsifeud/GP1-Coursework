#pragma once
#include <iostream>
#include <string>
#include <random>
#include "Window.h"
#include "Ground.h"
#include "Player.h"
#include "Alien.h"
#include "Barrier.h"
#include "Menu.h"
#include "Missile.h"
#include "Bomb.h"
#include "ScreenBuffer.h"
#include <array>
#include <vector>

#define GROUND 29
#define PLAYER 28
#define BARRIER 22
#define SPEED 2

class GameSource
{
public:
	GameSource();
	~GameSource();

	void setPlayerPoisiton();
	void setAlienPositions();
	void setBarrierPositions();
	void createBuffers(int width, int height);
	void initaliseGame();
	void processInput();
	void swapBuffers();
	void updateGame();
	void setGameState(int x);
	void setGamePositions(int width, int height);
	void checkCollision(int width, int height);
	void drawGame(int width, int height);
	void gameLoop();

	

private:
	bool m_runLoop = true;
	int switchBombDrops = 0;
	int randAlien = 0;
	Window m_gameWindow; // explain m_ convention
	Ground m_gameGround;

	std::unique_ptr<Menu> m_menu = std::make_unique<Menu>(); //smart pointers
	
	Player* m_player; // raw pointer lecture
	Missile m_missile;
	Bomb m_bomb;

	Alien m_aliens[20];
	ScreenBuffer m_frontBuffer;
	ScreenBuffer m_backBuffer;
	ScreenBuffer m_resetBuffer;

	std::vector<Barrier> m_barriers;

	enum gameState 
	{
		STARTSCREEN,
		LEVEL1,
		GAMEOVER,
		EXIT
	};

	gameState gS;
};