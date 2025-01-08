#pragma once
#include <functional>

class Tween {
private:
	long id;
	float from;
	float to;
	float duration;

	float value;
	float internalTimer;

	std::function<float(float)> easingFunction;
	std::function<void(float)> onUpdate;
	std::function<void()> onComplete;

public:
	bool complete;

	Tween(long id, float _from, float _to, float _duration);

	void SetOnUpdate(const std::function<void(float)> func) { onUpdate = func; }
	void SetOnComplete(const std::function<void()> func) { onComplete = func; }
	void SetEasingFunction(const std::function<float(float)> func) { easingFunction = func; }

	void UpdateValue(float deltaTime);

	float GetValue();
};
