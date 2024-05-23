#include "raylib.h"

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    int monitor = GetCurrentMonitor();
    InitWindow(GetMonitorWidth(monitor)/2, GetMonitorWidth(monitor)/2, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        monitor = GetCurrentMonitor();
        if (IsKeyPressed(KEY_F)) {
            if (IsWindowFullscreen()) {
                SetWindowSize(GetMonitorWidth(monitor)/2, GetMonitorWidth(monitor)/2);
                ToggleFullscreen();
            } else {
                SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
                ToggleFullscreen();
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            char text[] = "Congrats! You created your first window!";
            int textwidth = MeasureText(text, 20);
            DrawText(text, (GetRenderWidth() - textwidth)/2, (GetRenderHeight() - 20)/2, 20, LIGHTGRAY);
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
