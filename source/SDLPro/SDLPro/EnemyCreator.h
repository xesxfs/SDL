#pragma once
#include "BaseCreator.h"
#include "Enemy.h"
class EnemyCreator :
	public BaseCreator
{
public:
	EnemyCreator();
	~EnemyCreator();
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};

