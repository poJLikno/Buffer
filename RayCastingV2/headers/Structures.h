#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#include "main.h"

struct PlayerProperties
{
	float pos_x;
	float pos_y;
	float angle;
	float max_ray_depth;
	float FOV;
	float delta_angle;
};

#endif