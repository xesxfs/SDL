#pragma once
#include "SDLGameObject.h"
class MenuButton :
	public SDLGameObject
{
public:	
	MenuButton();
	~MenuButton();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);
	void(*m_callback)();
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
private:
	bool m_bReleased;
	 int m_callbackID;
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
};

