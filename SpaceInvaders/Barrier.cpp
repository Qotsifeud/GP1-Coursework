#include "Barrier.h"
int Barrier::x; // extra copy?

void Barrier::setPostion(int x, int y)
{
	this->xPos = x;
	this->yPos = y;
}

int Barrier::getXPostion()
{
	return this->xPos;
}

int Barrier::getYPostion()
{
	return this->yPos;
}

void Barrier::setHealth(int health)
{
	barrierHealth = health;
}

int Barrier::getHealth()
{
	return this->barrierHealth;
}

bool Barrier::isOnMissile(Missile m_missile)
{
	if (this->getXPos() == m_missile.getXPos() && this->getYPos() == m_missile.getYPos() && this->getState() == true && this->getHealth() > 0 && m_missile.getState() == true)
	{
		if (this->getHealth() == 1)
		{
			this->setHealth(this->getHealth() - 1);
			this->setState(false);
		}
		else
		{
			this->setHealth(this->getHealth() - 1);
		}

		return true;
	}

}

bool Barrier::isOnBomb(Bomb bomb)
{
	if (this->getXPos() == bomb.getXPos() && this->getYPos() == bomb.getYPos() && this->getState() == true && this->getHealth() > 0)
	{
		this->setHealth(this->getHealth() - 1);
		return true;
	}
	else if (this->getXPos() == bomb.getXPos() && this->getYPos() == bomb.getYPos() && this->getState() == true && this->getHealth() == 1)
	{
		this->setState(false);
		return true;
	}
	else
	{
		return false;
	}
}
