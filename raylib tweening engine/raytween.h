#pragma once
#include "tween.h"
#include <math.h>
#include <vector>
#include <memory>

float easeOutBounceHelper(float x);

#define EASE_LINEAR [](float x){return x;}
#define EASE_IN_SINE [](float x){return 1 - cos((x * PI) / 2);}
#define EASE_OUT_SINE [](float x){return sin((x * PI) / 2);}
#define EASE_IN_OUT_SINE [](float x){return -(cos(PI * x) - 1) / 2;}
#define EASE_IN_CUBIC [](float x){return x*x*x;}
#define EASE_OUT_CUBIC [](float x){return 1-pow(1-x, 3);}
#define EASE_IN_OUT_CUBIC [](float x){return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;}
#define EASE_IN_QUINT [](float x){return x * x * x * x * x;}
#define EASE_OUT_QUINT [](float x){return 1 - pow(1 - x, 5);}
#define EASE_IN_OUT_QUINT [](float x){return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;}
#define EASE_IN_CIRC [](float x){return 1 - sqrt(1 - pow(x, 2));}
#define EASE_OUT_CIRC [](float x){return sqrt(1 - pow(x - 1, 2));}
#define EASE_IN_OUT_CIRC [](float x){return x < 0.5 ? (1 - sqrt(1 - pow(2 * x, 2))) / 2 : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;}
#define EASE_IN_QUAD [](float x){return x*x;}
#define EASE_OUT_QUAD [](float x){return 1 - (1 - x) * (1 - x);}
#define EASE_IN_OUT_QUAD [](float x){return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;}
#define EASE_IN_QUART [](float x){return x*x*x*x;}
#define EASE_OUT_QUART [](float x){return 1 - pow(1 - x, 4);}
#define EASE_IN_OUT_QUART [](float x){return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;}
#define EASE_IN_EXPO [](float x){return x == 0 ? 0 : pow(2, 10 * x - 10);}
#define EASE_OUT_EXPO [](float x){return x == 1 ? 1 : 1 - pow(2, -10 * x);}
#define EASE_IN_OUT_EXPO [](float x){return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? pow(2, 20 * x - 10) / 2 : (2 - pow(2, -20 * x + 10)) / 2;}
#define EASE_IN_BACK [](float x){const float c1 = 1.70158; const float c3 = c1 + 1; return c3 * x * x * x - c1 * x * x;}
#define EASE_OUT_BACK [](float x){const float c1 = 1.70158; const float c3 = c1 + 1; return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2); }
#define EASE_IN_OUT_BACK [](float x){const float c1 = 1.70158; const float c2 = c1 * 1.525; return x < 0.5 ? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2 : (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2; }
#define EASE_OUT_BOUNCE [](float x){return easeOutBounceHelper(x);}
#define EASE_IN_BOUNCE [](float x){return 1 - easeOutBounceHelper(1 - x);}
#define EASE_IN_OUT_BOUNCE [](float x){return x < 0.5 ? (1 - easeOutBounceHelper(1 - 2 * x)) / 2 : (1 + easeOutBounceHelper(2 * x - 1)) / 2;}


class Raytween {
private:
	long incremental_id = 0;
	std::vector<std::shared_ptr<Tween>> tweens = {};
	std::vector<std::shared_ptr<Tween>> pendingTweens = {};
	Raytween(){}

public:
	static Raytween& GetInstance() {
		static Raytween instance;
		return instance;
	}
	Raytween(Raytween const&) = delete;
	void operator=(Raytween const&) = delete;

	static void DoTweens(float deltaTime);
	static std::shared_ptr<Tween> Value(
		float from,
		float to,
		float duration,
		std::function<float(float)> easingFunction = EASE_LINEAR
	);
};