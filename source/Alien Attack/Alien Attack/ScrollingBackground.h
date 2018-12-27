#pragma once
#include "LoaderParams.h"
#include "ShooterObject.h"
#include "SDL.h"
class ScrollingBackground:ShooterObject
{
public:
	ScrollingBackground();
	~ScrollingBackground();
	void load(std::unique_ptr<LoaderParams> const &pParams);
	void draw();
	void update();

private:
	int m_scrollSpeed;
	SDL_Rect m_srcRect1;
	SDL_Rect m_destRect1;

	SDL_Rect m_srcRect2;
	SDL_Rect m_destRect2;

	int count;
	int maxcount;
};

