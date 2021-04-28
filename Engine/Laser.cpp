#include "Laser.h"

void Laser::DrawLaser(Graphics & gfx, Player& player)
{
	temp = player.getXPos();
	if (counter == 0) {
		x = temp;
		counter++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			gfx.PutPixel(x + 13 + i, y - j, 190, 100, 50);
		}
	}
}

void Laser::Update()
{
	y -= 7;
	if (y <= 25) {
		bTopHit = true;
		y = 500;
	}
}

void Laser::LaserReset()
{
	counter = 0;
}

