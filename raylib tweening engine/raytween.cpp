#include <iostream>
#include "raytween.h"

float easeOutBounceHelper(float x)
{
	const float n1 = 7.5625;
	const float d1 = 2.75;

	if (x < 1 / d1) {
		return n1 * x * x;
	}
	else if (x < 2 / d1) {
		return n1 * (x -= 1.5 / d1) * x + 0.75;
	}
	else if (x < 2.5 / d1) {
		return n1 * (x -= 2.25 / d1) * x + 0.9375;
	}
	else {
		return n1 * (x -= 2.625 / d1) * x + 0.984375;
	}
}

void Raytween::DoTweens(float deltaTime)
{
	auto tweenIterator = Raytween::GetInstance().tweens.begin();

	for (tweenIterator; tweenIterator != Raytween::GetInstance().tweens.end(); tweenIterator++)
	{
		(*tweenIterator)->UpdateValue(deltaTime);

		if ((*tweenIterator)->complete) {
			tweenIterator = Raytween::GetInstance().tweens.erase(tweenIterator);
			if (tweenIterator == Raytween::GetInstance().tweens.end()) break;
		}
	}
}

std::shared_ptr<Tween> Raytween::Value(
	float from, 
	float to, 
	float duration, 
	std::function<float(float)> easingFunction
)
{
	std::shared_ptr<Tween> newTweenPtr = std::make_shared<Tween>(Raytween::GetInstance().incremental_id++, from, to, duration);
	newTweenPtr->SetEasingFunction(easingFunction);
	Raytween::GetInstance().tweens.push_back(newTweenPtr);
	return newTweenPtr;
}