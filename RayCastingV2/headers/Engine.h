#ifndef ENGINE_H_
#define ENGINE_H_

#include "main.h"

extern class Player;

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
	struct PlayerProperties* object = nullptr;
	POINT c_pos;

public:
	void Walk();
	void Mouse();

	GameControl(struct PlayerProperties* obj);
	~GameControl();
};

#endif