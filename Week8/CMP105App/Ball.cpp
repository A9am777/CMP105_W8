#include "Ball.h"

Ball::Ball()
{

}

Ball::~Ball()
{

}

void Ball::setPartner(Ball* newPartner)
{
	partner = newPartner;
}

void Ball::update(float dt)
{
	setPosition(getPosition() + velocity * dt);

	setCollisionBox(sf::FloatRect(getPosition().x,getPosition().y,getSize().x,getSize().y));
	if (Collision::checkBoundingCircle(this, partner))
	{
		velocity = -velocity;
	}
}
