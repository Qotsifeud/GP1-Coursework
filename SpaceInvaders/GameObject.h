#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class GameObject
{
public:

	GameObject() {}; // explain warning and how to fix it (something they should do for CW)
	GameObject(int x): xPos(x), yPos(0) {}; // overloading to initalise from the derived class
	~GameObject() {}; //destuctor

	virtual void update() {};
	virtual void draw() { std::cout << "called from based" << '\n'; };

	int getXPos() { return this->xPos; };
	int getYPos() { return this->yPos; };
#
	void setXPos(int x) { this->xPos = x; };
	void setYPos(int y) { this->yPos = y; };

protected: //explain protected access
	int xPos, yPos;
};