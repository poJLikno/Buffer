#include "../../headers/Engine.h"

extern LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

//Initialization
GameWindow::GameWindow(const char* window_name, HINSTANCE hInstance)
{
    WNDCLASS wc;
    memset(&wc, 0, sizeof(WNDCLASS));
    {
        wc.style = CS_OWNDC;
        wc.lpfnWndProc = WndProc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = hInstance;
        //wc.hIcon = (HICON)LoadImage(hInstance, "icon.ico", IMAGE_ICON, icon_width, icon_height, LR_LOADFROMFILE);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(6);
        wc.lpszMenuName = 0;
        wc.lpszClassName = "my_game_class";
    }
    if (!RegisterClass(&wc)) throw runtime_error("Couldn't register class");

    GameWindow::hwnd = CreateWindow(wc.lpszClassName, window_name, WS_POPUP, window_pos_x, window_pos_y, screen_width, screen_height, NULL, NULL, NULL, NULL);
    if (!GameWindow::hwnd) throw runtime_error("Couldn't create window");

    ShowWindow(GameWindow::hwnd, SW_SHOWNORMAL);
    ShowCursor(FALSE);

    TransformScreen();
}

//Parse messages
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

void GameWindow::TransformScreen()
{
    if (screen_transformation)
    {
        DEVMODE dm;
        dm.dmSize = sizeof(DEVMODE);
        int index = 0;
        while (EnumDisplaySettings(NULL, index, &dm))
        {
            if (dm.dmPelsWidth == screen_width && dm.dmPelsHeight == screen_height)
            {
                dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
                LONG result = ChangeDisplaySettings(&dm, CDS_FULLSCREEN);

                if (result == DISP_CHANGE_SUCCESSFUL) break;
                else if (result == DISP_CHANGE_RESTART)
                {
                    MessageBox(NULL, "Restart is reqired", "Error", MB_OK);
                    break;
                }
                else
                {
                    MessageBox(NULL, "Resolution isn't suppored", "Error", MB_OK);
                    break;
                }
            }
            index++;
        }
    }
}