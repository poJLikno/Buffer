#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "main.h"

const float PI = 3.1415927f;

//Screen
const bool screen_transformation = 0;

const unsigned short window_pos_x = 0;
const unsigned short window_pos_y = 0;

const unsigned short screen_width = 800;
const unsigned short screen_height = 600;

//Icon
const char icon_path[] = "icon.ico";
const unsigned short icon_width = 64;
const unsigned short icon_height = 64;

//Map
const unsigned short map_width = 600;
const unsigned short map_height = 600;

const char map[map_height / 100][map_width / 100 + 1] =
{
	"wwwwww",
	"w....w",
	"w.ww.w",
	"...w.w",
	"w....w",
	"wwwwww"
};

#endif
