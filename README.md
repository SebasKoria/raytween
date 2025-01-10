# RayTween

**RayTween** is a tweening engine specifically designed to integrate seamlessly with the [raylib](https://www.raylib.com/) graphics library. This engine provides an efficient and straightforward way to animate values smoothly using various easing functions.

## Features

-   **Easy-to-use interface:** Add tweening to your projects with just a few lines of code.
-   **Easing functions:** Access a variety of predefined easing functions, including linear, sine, cubic, elastic, and bounce.
-   **Singleton pattern:** Centralized management for all tweens.
-   **Callbacks:** Define actions for events such as value updates (`onUpdate`) and animation completion (`onComplete`).

## Requirements

-   **Language:** C++
-   **Graphics library:** [raylib](https://www.raylib.com/)
-   **Compiler:** Compatible with modern compilers, such as GCC, Clang, or MSVC.

> **Note:** RayTween is designed for C++ and is not compatible with C due to its use of lambdas, `std::function`, and other C++-specific features.

## Installation

1.  Clone the repository into your project
    ```bash
    git clone https://github.com/yourusername/raytween.git  
    
    ```
2.  Include the following files in your project:
    -   `raytween.h`
    -   `raytween.cpp`
    -   `tween.h`
    -   `tween.cpp`
3.  Ensure that raylib is linked when compiling your project.
4. Simply `#include "raytween.h"` and you're ready to go!

## Usage

### Example

This repository includes a `main.cpp` file demonstrating how to use RayTween. It serves as a practical example of implementing tweens in a raylib project, including animating a circle's position with easing functions.

### Creating a Tween

To animate a circle using the ease-out bounce function, call `Raytween::Value()` **only once** per tween. You can, however, create multiple tweens simultaneously or add new ones while others are running. The tween engine will handle all active animations.

### Parameters

-   **From:** The starting value.
-   **To:** The ending value.
-   **Duration:** Time in seconds for the animation to complete.
-   **Easing function:** The curve used to interpolate between values.

### Return Value

`Raytween::Value()` returns a `shared_ptr` to a `Tween` object, allowing you to configure callbacks such as `onUpdate()` and `onComplete()`.

-   `onUpdate()` is called every frame, whenever the value changes.
-   `onComplete()` is called once when the tween reaches its end value.

```cpp
while (!WindowShouldClose())  
{  
    /* ... */  

    Raytween::DoTweens(GetFrameTime()); // Ensure this is called inside the main loop

    if (IsKeyPressed(KEY_SPACE))
    {  
        Raytween::Value(100, 700, 1, EASE_OUT_BOUNCE)
            ->SetOnUpdate([&ballXPosition](float value) { ballXPosition = value; })
            ->SetOnComplete([]() { std::cout << "Complete!" << std::endl; });
    }  

    /* ... */  
}  

```

In this example, `ballXPosition` represents the X-axis position of a circle. Use `DrawCircle()` to visualize the animation.

### Available Easing Functions

RayTween offers numerous predefined easing functions, such as:

-   **Linear:** `EASE_LINEAR`
-   **Sine:** `EASE_IN_SINE`, `EASE_OUT_SINE`, `EASE_IN_OUT_SINE`
-   **Cubic:** `EASE_IN_CUBIC`, `EASE_OUT_CUBIC`, `EASE_IN_OUT_CUBIC`
-   **Bounce:** `EASE_IN_BOUNCE`, `EASE_OUT_BOUNCE`, `EASE_IN_OUT_BOUNCE`
-   **...and many more.**

Refer to `raytween.h` for the complete list of easing functions. You can also use this [easing function cheat sheet](https://easings.net/) to visually select the best easing curve for your project.

## Contributing

We welcome contributions! If you have ideas, bug fixes, or improvements, feel free to open an issue or submit a pull request.

## Thank You

Thank you for exploring RayTween! We hope it helps you create smooth and dynamic animations for your raylib projects.
