#ifndef ENGINE_H_
#define ENGINE_H_

#include "main.h"

//extern class Player;

class GameWindow
{
private:
	void TransformScreen();

public:
	HWND hwnd{};
	MSG msg{};

	GameWindow(const char* window_name, HINSTANCE hInstance);

	void ParseGameWindowMessages(MSG msg);
};

class GameGraphics
{
private:
	ULONG_PTR gdiplusToken{};
	ULONG_PTR* gdiplusTokenPointer = &gdiplusToken;

public:
	HDC buffer{};
	HBITMAP buffbit{};

	GameGraphics();
	~GameGraphics();

	void CreateDCBuffer(HDC dc);
	void ShowDCBuffer(HDC dc);
	void DeleteDCBuffer();
};

class GameControl
{
private:
	struct PlayerProperties* object = nullptr;
	POINT c_pos;

public:
	GameControl(struct PlayerProperties* obj);
	~GameControl();

	void Walk();
	void Mouse();
};

#endif