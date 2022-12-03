#include "../../headers/Engine.h"

HDC dc;
PAINTSTRUCT ps;
GameGraphics* paint = nullptr;
Player player(map_width / 2, map_height / 2, 30.f, 120.f, 300.f);
GameControl player_control(&player.player_properties);
MiniMap world_map;

//Messages
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (message == WM_CREATE)
    {
        paint = new GameGraphics();
        SetTimer(hwnd, 1, 10, NULL);
        return 0;
    }
    else if (message == WM_TIMER)
    {
        player_control.Walk();
        InvalidateRect(hwnd, NULL, FALSE);
        return 0;
    }
    else if (message == WM_PAINT)
    {
        dc = BeginPaint(hwnd, &ps);

        paint->CreateDCBuffer(dc);

        world_map.ShowMap(&paint->buffer, &player.player_properties, 1.f);

        paint->ShowDCBuffer(dc);
        paint->DeleteDCBuffer();

        EndPaint(hwnd, &ps);
        return 0;
    }
    else if (message == WM_MOUSEMOVE)
    {
        player_control.Mouse();
        return 0;
    }
    else if (message == WM_KEYDOWN)
    {
        if (wparam == VK_ESCAPE) DestroyWindow(hwnd);
        return 0;
    }
    else if (message == WM_CLOSE)
    {
        DestroyWindow(hwnd);
        return 0;
    }
    else if (message == WM_DESTROY)
    {
        delete paint;
        paint = nullptr;
        ReleaseDC(hwnd, dc);
        KillTimer(hwnd, 1);
        PostQuitMessage(0);
        return 0;
    }
    else return DefWindowProc(hwnd, message, wparam, lparam);
}