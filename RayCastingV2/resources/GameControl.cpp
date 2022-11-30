#include "../headers/Engine.h"

GameControl::GameControl(struct PlayerProperties* obj)
{
	object = obj;
	obj = nullptr;
}

GameControl::~GameControl()
{
	object = nullptr;
}

void GameControl::Walk()
{
	if (GetKeyState('W') < 0)
	{
		object->pos_x += 5.f * cos(object->angle * PI / 180.f);
		object->pos_y += 5.f * sin(object->angle * PI / 180.f);
	}
	if (GetKeyState('A') < 0)
	{
		object->pos_x += 5.f * cos((object->angle - 90.f) * PI / 180.f);
		object->pos_y += 5.f * sin((object->angle - 90.f) * PI / 180.f);
	}
	if (GetKeyState('S') < 0)
	{
		object->pos_x += 5.f * cos((object->angle + 180.f) * PI / 180.f);
		object->pos_y += 5.f * sin((object->angle + 180.f) * PI / 180.f);
	}
	if (GetKeyState('D') < 0)
	{
		object->pos_x += 5.f * cos((object->angle + 90.f) * PI / 180.f);
		object->pos_y += 5.f * sin((object->angle + 90.f) * PI / 180.f);
	}
}

void GameControl::Mouse()
{
	GetCursorPos(&c_pos);

	if (c_pos.x != screenwidth / 2)
	{
		object->angle += ((float)c_pos.x - (float)screenwidth / 2.f) / 10.f;
		SetCursorPos(screenwidth / 2, screenheight / 2);
	}
}