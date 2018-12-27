#include "Enemy.h"
#include "SDL.h"
Enemy::Enemy() {
	
}
void Enemy::draw()
{
	ShooterObject::draw(); // we now use SDLGameObject
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

	if (m_position.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400)
	{
		m_velocity.setY(-2);
	}
	ShooterObject::update();
}
void Enemy::load(std::unique_ptr<LoaderParams> const &pParams) {
	ShooterObject::load(pParams);
}

void Enemy::clean()
{
}

