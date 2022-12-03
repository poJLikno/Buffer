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

	void ParseGameWindowMessages(MSG msg);

	GameWindow(const char* window_name, HINSTANCE hInstance);
};

class GameGraphics
{
private:
	ULONG_PTR gdiplusToken{};
	ULONG_PTR* gdiplusTokenPointer = &gdiplusToken;

public:
	HDC buffer{};
	HBITMAP buffbit{};

	void CreateDCBuffer(HDC dc);
	void ShowDCBuffer(HDC dc);
	void DeleteDCBuffer();

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