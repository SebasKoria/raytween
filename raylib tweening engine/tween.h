#pragma once
#include <functional>
#include <memory>

class Tween : public std::enable_shared_from_this<Tween> {
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

	std::shared_ptr<Tween> SetOnUpdate(const std::function<void(float)> func);
	std::shared_ptr<Tween> SetOnComplete(const std::function<void()> func);
	void SetEasingFunction(const std::function<float(float)> func) { easingFunction = func; }

	void UpdateValue(float deltaTime);

	float GetValue();
};
