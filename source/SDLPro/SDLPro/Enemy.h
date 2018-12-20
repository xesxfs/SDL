#ifndef __Enemy__
#define __Enemy__
#include "SDLGameObject.h"

//#include "TextureManager.h"
//#include "Game.h"
class Enemy :public SDLGameObject
{
public:
	Enemy();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);
};
#endif

