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