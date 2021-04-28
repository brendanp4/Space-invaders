/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

	//Movement Controls
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		player.MoveRight();
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		player.MoveLeft();
	}
	//Shoot Control

	if (!bShoot) {
		if (wnd.kbd.KeyIsPressed(VK_SHIFT)) {
			bShoot = true;
			prevX = gx;
		}
	}
	if (bShoot && laser.bTopHit == false) {
		//Sound effect
		if (SoundPlayed < 2) {
			PlaySound(TEXT("shoot.wav"), NULL, SND_FILENAME | SND_ASYNC);
			SoundPlayed++;
		}
		//Fire laser
		laser.DrawLaser(gfx, player);
		laser.Update();
	}
	if (laser.bTopHit == true) {
		SoundPlayed--;
		bShoot = false;
		laser.LaserReset();
		laser.bTopHit = false;
	}

	//Check laser collision
	for (int i = 0; i < 12; i++) {
		alien[i].CheckHit(laser);
		if (alien[i].bShot) {
			laser.bTopHit = false;
		}
	}

	//Alien Movement
	if (frame == 200) {
		offSetY += 5;
	}
	if (frame == 400) {
		offSetX += 5;
	}
	if (frame == 500) {
		offSetX -= 5;
	}
	if (frame == 800) {
		offSetY += 5;
	}
	if (frame == 900) {
		offSetX -= 5;
	}
	if (frame == 1000) {
		offSetX += 5;
		frame = 0;
	}

	frame += 5;
}


void Game::ComposeFrame()
{
	player.DrawShip(gfx);
	player.ContainShip();
	for (int i = 0; i < 12; i++) {
		alien[i].Init(180 + (i * 26) + (i * 10) + offSetX, 200 + offSetY);
		if (!alien[i].Shot()) {
			alien[i].DrawAlien(gfx);
		}
	}
}
