#pragma once
#include "Player.h"
#include "Graphics.h"
class Laser
{
public:
	void DrawLaser(Graphics& gfx, Player& player);
	void Update();
	void LaserReset();
	int temp;
	int x;
	int y = 500;
	int counter = 0;
	bool bTopHit = false;
};

