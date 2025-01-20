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
	auto& instance = Raytween::GetInstance();
	auto& tweens = instance.tweens;
	auto& pendingTweens = instance.pendingTweens;

	for (auto it = tweens.begin(); it != tweens.end();)
	{
		(*it)->UpdateValue(deltaTime);

		if ((*it)->complete) {
			it = tweens.erase(it);
		}
		else {
			++it;
		}
	}

	if (!pendingTweens.empty()) {
		tweens.insert(tweens.end(), pendingTweens.begin(), pendingTweens.end());
		pendingTweens.clear();
	}
}

std::shared_ptr<Tween> Raytween::Value(
	float from, 
	float to, 
	float duration, 
	std::function<float(float)> easingFunction
)
{
	auto& instance = Raytween::GetInstance();
	std::shared_ptr<Tween> newTweenPtr = std::make_shared<Tween>(instance.incremental_id++, from, to, duration);
	newTweenPtr->SetEasingFunction(easingFunction);
	instance.pendingTweens.push_back(newTweenPtr);

	return newTweenPtr;
}