#include "Missile.h"

void Missile::fireMissile(Player& p)
{
	if (!isActive)
	{
		if (GetKeyState(32) & 0x8000)
		{
			xPos = p.getXPos();
			yPos = p.getYPos() - 1;
			isActive = true;
		}
	}
}

void Missile::update()
{
	if (isActive)
	{
		if (this->yPos > 0)
		{
			yPos--;
		}
		else
		{
			isActive = false;
		}
	}
}