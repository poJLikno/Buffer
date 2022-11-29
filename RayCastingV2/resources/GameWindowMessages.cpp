#include "../headers/Engine.h"

//Messages
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
    if (message == WM_KEYDOWN)
    {
        if (wparam == VK_ESCAPE) DestroyWindow(hwnd);
        return 0;
    }
    else if (message == WM_DESTROY)
    {
        PostQuitMessage(0);
        return 0;
    }
    else return DefWindowProc(hwnd, message, wparam, lparam);

    /*if (message == WM_CREATE)
    {
        paint = new GraphGDI();
        SetTimer(hwnd, 1, 10, NULL);
        return 0;
    }
    else if (message == WM_TIMER)
    {
        player1.CheckKeys();
        InvalidateRect(hwnd, NULL, FALSE);
        return 0;
    }
    else if (message == WM_PAINT)
    {
        dc = BeginPaint(hwnd, &ps);

        paint->CreateDCBufer(dc);

        worldmap.ShowMap(paint->bufer, player1.pos_x, player1.pos_y, player1.angle, player1.max_ray_depth, player1.FOV, player1.delta_angle, 1.f);

        paint->ShowDCBufer(dc);
        paint->DeleteDCBufer();

        EndPaint(hwnd, &ps);
        return 0;
    }
    else if (message == WM_KEYDOWN)
    {
        if (wparam == VK_ESCAPE) DestroyWindow(hwnd);
        return 0;
    }
    else if (message == WM_MOUSEMOVE)
    {
        player1.CheckMouse();
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
    else return DefWindowProc(hwnd, message, wparam, lparam);*/
}