#pragma once
#include "GameObject.h"
#include "Player.h"

class Missile : public GameObject
{
public:
	Missile(): isActive(false) {}
	void fireMissile(Player &p);
	void update();
	void setActive(bool state) { this->isActive = state; }
	bool getState() { return this->isActive; }
		
private:
	bool isActive;
};

