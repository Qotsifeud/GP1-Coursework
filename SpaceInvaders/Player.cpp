#include "Player.h"

void Player::update()
{
	extern int menuChoice;

	if (GetKeyState(65) & 0x8000)
	{
		if (xPos > 1)
			xPos--;
	}
	else if (GetKeyState(68) & 0x8000)
	{
		if (xPos < 79)
			xPos++;
	}
}

bool Player::playerCollisionCheck()
{
	return false;
}

