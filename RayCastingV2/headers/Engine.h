#ifndef ENGINE_H_
#define ENGINE_H_

#include "main.h"

class GameWindow
{
public:
	HWND hwnd{};
	MSG msg{};

	void ParseGameWindowMessages(MSG msg);

	GameWindow(const char* window_name, int window_pos_x, int window_pos_y, HINSTANCE hInstance);
};

#endif