#include "Alien.h"

Alien::Alien(const Alien& other)
{
	//std::cout << " A copy of alien has been made" << '\n';
}

void Alien::setPostion(int x, int y)
{
	xPos = x;
	yPos = y;
	movingRight = true;

}

void Alien::setActive(bool state) 
{
	this->m_isActive = state;
}

bool Alien::isOnMissile(Missile m_missile)
{
	if ((this->getXP()) == m_missile.getXPos() + 1 && this->getYP() == m_missile.getYPos() && this->getState() == true && m_missile.getState() == true)
	{
		this->setActive(false);
		return true;
	}
	else
	{
		return false;
	}
}

bool Alien::isOnPlayer(Player* m_player)
{

	if (this->getYP() == m_player->getYPos())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Alien::draw()
{
	std::cout << "X";
}

void Alien::setSpeed(int x)
{
	this->m_speed = x;
}

void Alien::update()
{
	if (m_isActive == true)
	{
		if (movingRight)
		{
			if (xPos >= 0 && xPos != 75)
			{
				xPos++;
				movingRight = true;
			}
			else if (xPos == 75)
			{
				yPos++;
				movingRight = false;
			}
		}
		else
		{
			if (xPos != 0)
			{
				xPos--;
			}
			else
			{
				yPos++;
				movingRight = true;
			}
		}
		
	}
}
