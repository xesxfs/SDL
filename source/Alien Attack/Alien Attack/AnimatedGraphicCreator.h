#pragma once
#include "BaseCreator.h"
#include "AnimatedGraphic.h"
class AnimatedGraphicCreator :
	public BaseCreator
{
public:
	AnimatedGraphicCreator();
	~AnimatedGraphicCreator();
	GameObject* createGameObject() const
	{
		return new AnimatedGraphic();
	}
};

