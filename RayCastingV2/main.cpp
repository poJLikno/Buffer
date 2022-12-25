#include "headers/main.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prev, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    try
    {
        GameWindow game_window("Game", hInstance);
        game_window.ParseGameWindowMessages(game_window.msg);
    }
    catch (runtime_error error)
    {
        MessageBox(NULL, error.what(), "Error", MB_OK);
    }

    return 0;
}