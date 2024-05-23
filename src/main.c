#include "raylib.h"

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    int monitor = GetCurrentMonitor();
    InitWindow(GetMonitorWidth(monitor)/2, GetMonitorWidth(monitor)/2, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_F)) {
            if (IsWindowFullscreen()) {
                monitor = GetCurrentMonitor();
                SetWindowSize(GetMonitorWidth(monitor)/2, GetMonitorWidth(monitor)/2);
                ToggleFullscreen();
            } else {
                monitor = GetCurrentMonitor();
                SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
                ToggleFullscreen();
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
