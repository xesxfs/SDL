#include "AnimatedGraphic.h"
#include "SDL.h"
AnimatedGraphic::AnimatedGraphic() : ShooterObject()
{
	
}

void AnimatedGraphic::load(std::unique_ptr<LoaderParams> const &pParams)
{
	ShooterObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::draw()
{
	ShooterObject::draw();
}

void AnimatedGraphic::clean()
{
	ShooterObject::clean();
}

