#include "GameSource.h"

int Alien::m_speed; // define static variable

double randomNum() {

	static std::default_random_engine rng;

	std::uniform_real_distribution<double> dist(0, 19);
	return dist(rng);
};

extern int menuChoice;

GameSource::GameSource() : m_player(new Player()), m_barriers(20) {} // heap allocatoin (explain new and pointer)

GameSource::~GameSource()
{
	delete m_player;
}; // ";" is not needed but is will not break the code

void GameSource::setPlayerPoisiton()
{
	m_player->setXPos(15);
	m_player->setYPos(PLAYER);
}

void GameSource::setAlienPositions()
{
	for (int i = 0; i < 20; i++)
	{
		m_aliens[i].setPostion(i * 3, 1);
		m_aliens[i].setActive(true);
	}
}

void GameSource::setBarrierPositions()
{
	for (int i = 0; i < 20; i++)
	{
		m_barriers.emplace_back(Barrier());
	}

	for (int i = 0; i < 5; i++)
	{
		m_barriers[i].setPostion(i + 10, BARRIER);
		m_barriers[i].setHealth(2);
	}
	for (int i = 5; i < 10; i++)
	{
		m_barriers[i].setPostion(i + 25, BARRIER);
		m_barriers[i].setHealth(2);
	}
	for (int i = 10; i < 15; i++)
	{
		m_barriers[i].setPostion(i + 40, BARRIER);
		m_barriers[i].setHealth(2);
	}
	for (int i = 15; i < 20; i++)
	{
		m_barriers[i].setPostion(i + 55, BARRIER);
		m_barriers[i].setHealth(2);
	}
}


void GameSource::initaliseGame()
{
	m_gameWindow.setWindow(90, 30);
	createBuffers(90, 30);
	setPlayerPoisiton();
	setAlienPositions();
	setBarrierPositions();

	m_currentLevel = 1;

	highScoreFile.open("highScore.txt");
	getline(highScoreFile, m_highScore);
	highScoreFile.close();

	levelText = "Level: " + std::to_string(m_currentLevel);
	highScoreText = "High Score: " + m_highScore;
}

void GameSource::processInput()
{
	m_player->update();
	m_missile.fireMissile(*m_player);
}

void GameSource::updateGame()
{
	int x;

	x = m_aliens[0].getYP() > SPEED ? 2 : 1; //Ternary Operator - Same as below

	for (int i = 0; i < 20; i++)
	{
		m_aliens[i].setSpeed(x);
		m_aliens[i].update();
	}

	if (!m_bomb.getState())
	{
		randAlien = randomNum();

		switch (switchBombDrops)
		{
			case 0:

				if (m_aliens[randAlien].getState() == true)
				{
					m_bomb.fireBomb(m_aliens[randAlien]);
					switchBombDrops = 1;
				}
				else
				{
					switchBombDrops = 1;
				}

				break;

			case 1:

				for (int i = 0; i < 20; i++)
				{
					if (m_aliens[i].getXP() == m_player->getXPos() && m_aliens[i].getState() == true);
					{
						m_bomb.fireBomb(m_aliens[i]);
						switchBombDrops = 0;
					}
				}
				break;
		}
	}

	if (aliensActiveCheck = false)
	{
		gS = LEVEL2;
	}
}

void GameSource::setGameState(int x)
{
	gS = static_cast<gameState>(x); //casting lecture
}

void GameSource::setGamePositions(int width, int height)  //potentially save and read from textfile?
{ //Break here to show copies (Dynamic vs Static array)
	for (int i = 0; i < height; i++)
	{
		if (i == LEVEL)
		{
			for (int j = 75; j <= 90; j++)
			{
				for (int l = 0; l < levelText.length(); l++)
				{
					m_backBuffer.setChar(i, j, levelText[l]);
				}
			}
		}

		/*if (i == HIGHSCORE)
		{
			for (int j = 75; j <= 90; j++)
			{
				for (int l = 0; l < highScoreText.length(); l++)
				{
					m_backBuffer.setChar(i, j, highScoreText[l]);
				}
			}
		}*/

		for (int j = 0; j < width; j++) // draw aliens
		{
			for (int aNo = 0; aNo < 20; aNo++) //3rd for loop, can this be improved? 2D array
			{
				if ((m_aliens[aNo].getYP() == i) && (m_aliens[aNo].getXP() == j) && (m_aliens[aNo].getState() == true))
				{
					m_backBuffer.setChar(m_aliens[aNo].getXP(), m_aliens[aNo].getYP(), 'X');
				}
			}
		}

		if (i == (BARRIER)) //draw barriers (explain the macro (openGL))
		{
			for (int j = 0; j < width; j++)
			{
				for (unsigned int bNo = 0; bNo < m_barriers.size(); bNo++) // unsigned explain
				{
					if (m_barriers[bNo].getHealth() == 2 && m_barriers[bNo].getState() == true && m_barriers[bNo].getXPostion() == j)
					{
						m_backBuffer.setChar(m_barriers[bNo].getXPostion(), BARRIER, '=');
					}
					else if (m_barriers[bNo].getHealth() == 1 && m_barriers[bNo].getState() == true && m_barriers[bNo].getXPostion() == j)
					{
						m_backBuffer.setChar(m_barriers[bNo].getXPostion(), BARRIER, '-');
					}
				}
			}
		}

		if (i == (PLAYER)) //draw player
		{
			for (int j = 0; j < width; j++)
				if (m_player->getXPos() == j)
				{
					m_backBuffer.setChar(m_player->getXPos(), PLAYER, '^');
				}
		}


		else if (i == (GROUND))	//draw ground
		{
			for (int j = 0; j < width; j++)
				m_backBuffer.setChar(j, GROUND, '-');
		}
	}


	if (m_missile.getState() == true)
	{
		m_backBuffer.setChar(m_missile.getXPos(), m_missile.getYPos(), '|');
		m_missile.update();
	}

	if (m_bomb.getState() == true)
	{
		m_backBuffer.setChar(m_bomb.getXPos(), m_bomb.getYPos(), '*');
		m_bomb.update();
	}


};

void GameSource::drawGame(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			m_gameWindow.setCursorPosition(j, i);
			std::cout << m_frontBuffer.getChar(j, i);
		}
	}
}

void GameSource::createBuffers(int width, int height)
{
	// create the front buffer
	m_frontBuffer = ScreenBuffer(width, height);
	// create the back buffer
	m_backBuffer = ScreenBuffer(width, height);
	// create the reset buffer
	m_resetBuffer = ScreenBuffer(width, height);

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			m_resetBuffer.setChar(i, j, ' ');

	m_frontBuffer = m_resetBuffer;
	m_backBuffer = m_resetBuffer;

}
void GameSource::swapBuffers()
{
	swap(m_frontBuffer, m_backBuffer);
	m_backBuffer = m_resetBuffer;
}

void GameSource::checkCollision(int width, int height)
{
	for (Barrier& barrier : m_barriers)
	{
		if (barrier.isOnMissile(m_missile) == true)
		{
			m_missile.setActive(false);
		}
	}

	for (Alien& alien : m_aliens)
	{
		if (alien.isOnPlayer(m_player) == true)
		{
			setGameState(GAMEOVER);
		}
		else if (alien.isOnMissile(m_missile))
		{
			m_missile.setActive(false);
		}
	}


	if (m_bomb.getState() == true)
	{
		for (Barrier& barrier : m_barriers)
		{
			if (barrier.isOnBomb(m_bomb))
			{
				m_bomb.setActive(false);
			}
		}

		
		if (m_bomb.isOnPlayer(m_player) == true)
		{
			setGameState(GAMEOVER);
			m_bomb.setActive(false);
		}
		else if (m_bomb.isOnGround(GROUND) == true)
		{
			m_bomb.setActive(false);
		}
		if (m_missile.getState())
		{
			if (m_bomb.isOnMissile(m_missile) == true)
			{
				m_bomb.setActive(false);
				m_missile.setActive(false);
			}
		}
	}
}

void GameSource::alienStatusCheck()
{
	for (Alien a : m_aliens)
	{
		if (a.getState())
		{
			aliensActiveCheck = true;
			continue;
		}
		else
		{
			aliensActiveCheck = false;
		}
	}
}

void GameSource::gameLoop()
{
	while (gS != gameState::EXIT)
	{

		switch (gS)
		{
		case STARTSCREEN:
			m_menu->run();
			this->setGameState(menuChoice);
			break;
		case LEVEL1:
			this->processInput();
			this->updateGame();
			this->setGamePositions(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			this->checkCollision(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			this->swapBuffers();
			this->drawGame(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			break;
		case LEVEL2:
			this->processInput();
			this->updateGame();
			this->setGamePositions(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			this->checkCollision(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			this->swapBuffers();
			this->drawGame(m_gameWindow.getWidth(), m_gameWindow.getHeight());
		case GAMEOVER:
			m_menu->gameOver();
			if (menuChoice == 1)
			{
				this->setGameState(LEVEL1); // Restart the game at LEVEL1
				this->initaliseGame();
			}
			break;
		}

	}
}
