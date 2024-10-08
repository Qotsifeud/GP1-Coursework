#pragma once
#include "GameObject.h"
#include "Alien.h"

class Bomb : public GameObject
{
public:
	Bomb() : isActive(false) {};
	void fireBomb(Alien &a);
	void update();
	void setActive(bool state) { this->isActive = state; }
	bool getState() { return this->isActive; }

	int getXP() { return this->xPos; };
	int getYP() { return this->yPos; };

	bool isOnPlayer(Player* player);
	bool isOnGround(int ground);
	bool isOnMissile(Missile missile);

private:
	bool isActive;
};

