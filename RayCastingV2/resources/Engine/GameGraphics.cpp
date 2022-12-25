#include "../../headers/Engine.h"

//Initialization
GameGraphics::GameGraphics()
{
    GdiplusStartupInput gdiplusStartupInput{};
    GdiplusStartup(GameGraphics::gdiplusTokenPointer, &gdiplusStartupInput, NULL);
}

GameGraphics::~GameGraphics()
{
    GameGraphics::gdiplusTokenPointer = nullptr;
    GdiplusShutdown(GameGraphics::gdiplusToken);
}

//Buffer
void GameGraphics::CreateDCBuffer(HDC dc)
{
    buffer = CreateCompatibleDC(dc);
    buffbit = CreateCompatibleBitmap(dc, screen_width, screen_height);
    SelectObject(buffer, buffbit);

    SelectObject(buffer, GetStockObject(DC_BRUSH));
    SelectObject(buffer, GetStockObject(DC_PEN));
}

void GameGraphics::ShowDCBuffer(HDC dc)
{
    BitBlt(dc, 0, 0, screen_width, screen_height, buffer, 0, 0, SRCCOPY);
}

void GameGraphics::DeleteDCBuffer()
{
    DeleteDC(buffer);
    DeleteObject(buffbit);
}