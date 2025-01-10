#include <raylib.h>
#include <iostream>
#include "raytween.h"

std::string controls1 =
    "Q - Ease Linear\n"
    "W - Ease In Sine\n"
    "E - Ease Out Sine\n"
    "R - Ease In Out Sine\n"
    "T - Ease In Cubic\n"
    "Y - Ease Out Cubic\n"
    "U - Ease In Out Cubic\n";

std::string controls2 =
    "I - Ease In Quint\n"
    "O - Ease Out Quint\n"
    "P - Ease In Out Quint\n"
    "A - Ease In Circ\n"
    "S - Ease Out Circ\n"
    "D - Ease In Out Circ\n"
    "F - Ease In Quad\n";

std::string controls3 =
    "G - Ease Out Quad\n"
    "H - Ease In Out Quad\n"
    "J - Ease In Quart\n"
    "K - Ease Out Quart\n"
    "L - Ease In Out Quart\n"
    "Z- Ease In Expo\n"
    "X - Ease Out Expo\n";

std::string controls4 =
    "C - Ease In Out Expo\n"
    "V - Ease In Back\n"
    "B - Ease Out Back\n"
    "N - Ease In Out Back\n"
    "M - Ease In Bounce\n"
    ", - Ease Out Bounce\n"
    ". - Ease In Out Bounce\n";

std::function<float(float)> GetEasing(int key);

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    float ballXPosition = 100;

    InitWindow(screenWidth, screenHeight, "Raytween demonstration project");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        Raytween::DoTweens(GetFrameTime());

       int keyPressed = GetKeyPressed();

        if (keyPressed != 0) {
            Raytween::Value(100, 700, 1, GetEasing(keyPressed))
                ->SetOnUpdate([&ballXPosition](float value) {
                    ballXPosition = value;
                });
        }

        ClearBackground(RAYWHITE);
        DrawCircle(ballXPosition, 225, 20, RED);

        DrawText("Press any key to preview the easing animation:", 10, 10, 10, BLACK);
        DrawText(controls1.c_str(), 10, 25, 10, BLACK);
        DrawText(controls2.c_str(), 150, 25, 10, BLACK);
        DrawText(controls3.c_str(), 300, 25, 10, BLACK);
        DrawText(controls4.c_str(), 450, 25, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

std::function<float(float)> GetEasing(int key)
{
    std::function<float(float)> func;

    switch (key) {
        case KEY_Q: func = EASE_LINEAR; break;
        case KEY_W: func = EASE_IN_SINE; break;
        case KEY_E: func = EASE_OUT_SINE; break;
        case KEY_R: func = EASE_IN_OUT_SINE; break;
        case KEY_T: func = EASE_IN_CUBIC; break;
        case KEY_Y: func = EASE_OUT_CUBIC; break;
        case KEY_U: func = EASE_IN_OUT_CUBIC; break;
        case KEY_I: func = EASE_IN_QUINT; break;
        case KEY_O: func = EASE_OUT_QUINT; break;
        case KEY_P: func = EASE_IN_OUT_QUINT; break;
        case KEY_A: func = EASE_IN_CIRC; break;
        case KEY_S: func = EASE_OUT_CIRC; break;
        case KEY_D: func = EASE_IN_OUT_CIRC; break;
        case KEY_F: func = EASE_IN_QUAD; break;
        case KEY_G: func = EASE_OUT_QUAD; break;
        case KEY_H: func = EASE_IN_OUT_QUAD; break;
        case KEY_J: func = EASE_IN_QUART; break;
        case KEY_K: func = EASE_OUT_QUART; break;
        case KEY_L: func = EASE_IN_OUT_QUART; break;
        case KEY_Z: func = EASE_IN_EXPO; break;
        case KEY_X: func = EASE_OUT_EXPO; break;
        case KEY_C: func = EASE_IN_OUT_EXPO; break;
        case KEY_V: func = EASE_IN_BACK; break;
        case KEY_B: func = EASE_OUT_BACK; break;
        case KEY_N: func = EASE_IN_OUT_BACK; break;
        case KEY_M: func = EASE_IN_BOUNCE; break;
        case KEY_COMMA: func = EASE_OUT_BOUNCE; break;
        case KEY_PERIOD: func = EASE_IN_OUT_BOUNCE; break;
        default: func = EASE_LINEAR; break;
    }

    return func;
}