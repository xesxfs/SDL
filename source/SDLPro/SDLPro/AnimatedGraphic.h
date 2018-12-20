#pragma once
#include "SDLGameObject.h"
class AnimatedGraphic :
	public SDLGameObject
{
public:
	AnimatedGraphic();
	~AnimatedGraphic();

	virtual void draw();
	virtual void update();
	virtual void clean();	
	virtual void load(const LoaderParams* pParams);
private:
	int m_animSpeed;


};


