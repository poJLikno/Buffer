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

class MiniMap
{
private:
	HDC dc;
	float scale;
	struct PlayerProperties* object = nullptr;
	float cur_angle;

	void DrawWalls();
	void DrawRays();
	void DrawPlayer();

public:
	const char map[map_height / 100][map_width / 100 + 1] =
	{
		"wwwwww",
		"w....w",
		"w.ww.w",
		"...w.w",
		"w....w",
		"wwwwww"
	};

	float VerticalCross();
	float HorizontalCross();
	float NearestCross();
	void ShowMap(HDC* dc, struct PlayerProperties* obj, float scale);
};

#endif