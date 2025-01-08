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
		onComplete();
	}
	else
	{
		value = easingFunction(internalTimer / duration) * (to - from) + from;
		onUpdate(value);
	}
}

float Tween::GetValue() { return value; }
