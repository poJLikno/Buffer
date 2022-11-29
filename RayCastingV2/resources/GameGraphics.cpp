#include "../headers/Engine.h"

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

/*//Bufer
void GraphGDI::CreateDCBufer(HDC dc)
{
    GraphGDI::bufer = CreateCompatibleDC(dc);
    GraphGDI::bufbit = CreateCompatibleBitmap(dc, screenwidth, screenheight);
    SelectObject(GraphGDI::bufer, GraphGDI::bufbit);

    SelectObject(GraphGDI::bufer, GetStockObject(DC_BRUSH));
    SelectObject(GraphGDI::bufer, GetStockObject(DC_PEN));
}

void GraphGDI::ShowDCBufer(HDC dc)
{
    BitBlt(dc, 0, 0, screenwidth, screenheight, GraphGDI::bufer, 0, 0, SRCCOPY);
}

void GraphGDI::DeleteDCBufer()
{
    DeleteDC(GraphGDI::bufer);
    DeleteObject(GraphGDI::bufbit);
}*/