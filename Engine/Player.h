#pragma once
#include "Graphics.h"

class Player
{
public:
	Player() {

	}
	void DrawShip(Graphics& gfx);
	void ContainShip();
	void MoveLeft();
	void MoveRight();
	int getXPos();
private:
	static constexpr int width = 26;
	static constexpr int height = 26;
	int laserY = 500;
	int prevX = 0;
	int x = 188;
	int y = 500;
};

