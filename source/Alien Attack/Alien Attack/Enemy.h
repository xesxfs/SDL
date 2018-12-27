#ifndef __Enemy__
#define __Enemy__
#include "ShooterObject.h"

//#include "TextureManager.h"
//#include "Game.h"
class Enemy :public ShooterObject
{
public:
	virtual std::string type() { return"Enemy"; }
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(std::unique_ptr<LoaderParams> const &pParams);
protected:
	int m_health;
	Enemy() : ShooterObject() {}
	virtual ~Enemy() {} // for polymorphism
};
#endif

