#include "Bomb.h"

void Bomb::fireBomb(Alien &a)
{
	if (!isActive)
	{
		xPos = a.getXP();
		yPos = a.getYP();
		isActive = true;
	}
}

void Bomb::update()
{
	if (isActive)
	{
		if (this->yPos < 29)
		{
			yPos++;
		}
		else
		{
			isActive = false;
		}
	}
}

bool Bomb::isOnPlayer(Player* player)
{
	if (this->getXPos() == player->getXPos() && this->getYPos() == player->getYPos())
	{
		return true;
	}
}

bool Bomb::isOnGround(int ground)
{
	if (this->yPos == ground)
	{
		return true;
	}
}

bool Bomb::isOnMissile(Missile missile)
{
	if (this->getYPos() == missile.getYPos() && this->getXPos() == missile.getXPos())
	{
		return true;
	}
}
