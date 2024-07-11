#include "Alien.h"

Alien::Alien(const Alien& other)
{
	//std::cout << " A copy of alien has been made" << '\n';
}

void Alien::setPostion(int x, int y)
{
	xPos = x;
	yPos = y;
}

void Alien::setActive(bool state) 
{
	this->m_isActive = state;
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
		if (xPos >= 0 && xPos != 75)
		{
			xPos++;
		}
		else if (xPos == 75)
		{
			yPos++;

			do
			{
				xPos--;
			} while (xPos != 5);
		}
	}
}
