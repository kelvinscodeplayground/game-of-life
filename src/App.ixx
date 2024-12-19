export module App;

#include <raylib.h>

namespace app {
export int main(int argc, char **argv)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
}
