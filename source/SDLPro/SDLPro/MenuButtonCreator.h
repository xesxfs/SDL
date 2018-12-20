#pragma once
#include "BaseCreator.h"
#include "MenuButton.h"
class MenuButtonCreator :
	public BaseCreator
{
public:
	MenuButtonCreator();
	~MenuButtonCreator();
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};

