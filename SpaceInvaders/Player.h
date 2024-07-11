#pragma once
#include "GameObject.h"
#include "GameSource.h"

class Player: public GameObject
{
public:
	Player(): GameObject(10) {}; //member initilasion in derived class

	void update() override;
};

