#pragma once
#include "Graphics.h"
#include "Player.h"
#include "Laser.h"
class Alien
{
public:
	void Init(int posX, int posY);
	void DrawAlien(Graphics& gfx);
	void CheckHit(Laser& laser);
	bool Shot();
	bool bShot;
private:
	static constexpr int width = 26;
	static constexpr int height = 19;
	int x = 160;
	int y = 200;
};

