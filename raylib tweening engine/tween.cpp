#include "tween.h"

Tween::Tween(long _id, float _from, float _to, float _duration)
	: id(_id)
	, from(_from)
	, to(_to)
	, duration(_duration)
{
	value = 0;
	internalTimer = 0;
	complete = false;

	onUpdate = [](float _) {};
	onComplete = []() {};
	easingFunction = [](float x) {return x; };
}

void Tween::UpdateValue(float deltaTime) 
{
	if (complete) return;
	internalTimer += deltaTime;

	if (internalTimer == 0)
	{
		value = from;
		onUpdate(value);
	}
	else if (internalTimer >= duration)
	{
		value = to;
		complete = true;
		onUpdate(value);
		onComplete();
	}
	else
	{
		value = easingFunction(internalTimer / duration) * (to - from) + from;
		onUpdate(value);
	}
}

float Tween::GetValue() { return value; }

std::shared_ptr<Tween> Tween::SetOnUpdate(const std::function<void(float)> func)
{
	onUpdate = func;
	return shared_from_this();
}

std::shared_ptr<Tween> Tween::SetOnComplete(const std::function<void()> func)
{
	onComplete = func;
	return shared_from_this();
}
