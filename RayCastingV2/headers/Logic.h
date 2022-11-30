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

/*class MiniMap
{
public:
	MiniMap();
	~MiniMap();
};*/

#endif