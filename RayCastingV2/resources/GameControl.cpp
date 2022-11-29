#include "../headers/Engine.h"

GameControl::GameControl(float pos_x, float pos_y, float angle)
{
	GameControl::pos_x = &pos_x;
	GameControl::pos_y = &pos_y;
	GameControl::angle = &angle;
}

GameControl::~GameControl()
{
	GameControl::pos_x = nullptr;
	GameControl::pos_y = nullptr;
	GameControl::angle = nullptr;
}

void GameControl::Walk()
{
	if (GetKeyState('W') < 0)
	{
		*GameControl::pos_x += 5.f * cos(*GameControl::angle * PI / 180.f);
		*GameControl::pos_y += 5.f * sin(*GameControl::angle * PI / 180.f);
	}
	if (GetKeyState('A') < 0)
	{
		*GameControl::pos_x += 5.f * cos((*GameControl::angle - 90.f) * PI / 180.f);
		*GameControl::pos_y += 5.f * sin((*GameControl::angle - 90.f) * PI / 180.f);
	}
	if (GetKeyState('S') < 0)
	{
		*GameControl::pos_x += 5.f * cos((*GameControl::angle + 180.f) * PI / 180.f);
		*GameControl::pos_y += 5.f * sin((*GameControl::angle + 180.f) * PI / 180.f);
	}
	if (GetKeyState('D') < 0)
	{
		*GameControl::pos_x += 5.f * cos((*GameControl::angle + 90.f) * PI / 180.f);
		*GameControl::pos_y += 5.f * sin((*GameControl::angle + 90.f) * PI / 180.f);
	}
}