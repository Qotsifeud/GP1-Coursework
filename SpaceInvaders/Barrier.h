#pragma once
#include "GameObject.h"
#include "Missile.h"
#include "Bomb.h"

class Barrier : public GameObject
{
public:

	Barrier() : isActive(true) {};
	
	Barrier(const Barrier& other) 
		: isActive(other.isActive){};
	
	~Barrier() {};

	void setPostion(int x, int y);

	void setHealth(int health);

	int getXPostion();
	int getYPostion();
	int getHealth();

	void setState(bool in) { isActive = in; };
	bool getState() { return isActive; }

	bool isOnMissile(Missile missile);
	bool isOnBomb(Bomb bomb);

private:
	int barrierHealth;
	static int x;
	bool isActive;
};

