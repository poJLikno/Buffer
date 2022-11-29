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

class GameGraphics
{
private:
	ULONG_PTR gdiplusToken{};
	ULONG_PTR* gdiplusTokenPointer = &gdiplusToken;

public:
	/*
	HDC bufer{};
	HBITMAP bufbit{};

	void CreateDCBufer(HDC dc);
	void ShowDCBufer(HDC dc);
	void DeleteDCBufer();
	*/
	GameGraphics();
	~GameGraphics();
};

class GameControl
{
private:
	float* pos_x = nullptr;
	float* pos_y = nullptr;
	float* angle = nullptr;

public:
	void Walk();

	GameControl(float pos_x, float pos_y, float angle);
	~GameControl();
};

#endif