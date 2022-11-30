#include "../headers/Logic.h"

Player::Player(float pos_x, float pos_y, float angle, float FOV, float max_ray_depth)
{
	player_properties.pos_x = pos_x;
	player_properties.pos_y = pos_y;
	player_properties.angle = angle;
	player_properties.FOV = FOV;
	player_properties.max_ray_depth = max_ray_depth;
	player_properties.delta_angle = FOV / (float)screenwidth;
}