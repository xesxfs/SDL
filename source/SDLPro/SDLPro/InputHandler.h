#pragma once
#include<vector>
#include "SDL.h"
#include "Vector2D.h"
class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	void initialiseJoysticks();

	// handle keyboard events
	void onKeyDown();
	void onKeyUp();

	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	// handle joysticks events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);


	bool joysticksInitialised() {
		return m_bJoysticksInitialised;
	}

	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	bool isKeyDown(SDL_Scancode key);

private:
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialised;

	Vector2D* m_mousePosition;
	std::vector<bool> m_mouseButtonStates;

	const Uint8* m_keystates;


	InputHandler();
	~InputHandler();
	static InputHandler* s_pInstance;
};
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
typedef InputHandler TheInputHandler;

