#include "../headers/Engine.h"

extern LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

GameWindow::GameWindow(const char* window_name, int window_pos_x, int window_pos_y, HINSTANCE hInstance)
{
    WNDCLASS wc;
    memset(&wc, 0, sizeof(WNDCLASS));
    {
        wc.style = CS_OWNDC;
        wc.lpfnWndProc = WndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        wc.hIcon = (HICON)LoadImage(hInstance, "icon.ico", IMAGE_ICON, iconwidth, iconheight, LR_LOADFROMFILE);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(6);
        wc.lpszMenuName = 0;
        wc.lpszClassName = "my_game_class";
    }
    if (!RegisterClass(&wc)) throw runtime_error("Couldn't register class");

    GameWindow::hwnd = CreateWindow(wc.lpszClassName, window_name, WS_POPUP, window_pos_x, window_pos_y, screenwidth, screenheight, NULL, NULL, NULL, NULL);
    if (!GameWindow::hwnd) throw runtime_error("Couldn't create window");

    ShowWindow(GameWindow::hwnd, SW_SHOWNORMAL);
    ShowCursor(FALSE);
}

void GameWindow::ParseGameWindowMessages(MSG msg)
{
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (GetForegroundWindow() == GameWindow::hwnd)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}