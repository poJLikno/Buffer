#ifndef LOGIC_H_
#define LOGIC_H_

#include "main.h"

class Player
{
public:
	struct PlayerProperties player_properties;

	Player(float pos_x, float pos_y, float angle, float FOV, float max_ray_depth);
	//~Player();
};

class GUI
{
private:
	HDC* dc = nullptr;
	float scale;
	struct PlayerProperties* object = nullptr;
	float cur_angle;
	float crosses[screen_width];

	void DrawWallsMap();
	void DrawRaysMap();
	void DrawPlayerMap();

public:
	void DrawMap(HDC* dc, struct PlayerProperties* obj, float crosses[screen_width], float scale);
};

class Canvas
{
private:
	HDC* dc = nullptr;
	PlayerProperties* object = nullptr;
	float cur_angle;

	float VerticalCross();
	float HorizontalCross();
	float NearestCross();

public:
	float crosses[screen_width];

	void DrawCanvas(HDC* hdc, PlayerProperties* obj);
};

#endif