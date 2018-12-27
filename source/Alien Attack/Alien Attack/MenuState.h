#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"
class MenuState :
	public GameState
{
public:
	MenuState();
	~MenuState();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
	std::vector<GameObject*> m_gameObjects;
protected:
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks)= 0;
	std::vector<Callback> m_callbacks;
	static const std::string s_menuID;
private:


};

