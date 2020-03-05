#include "PongBall.h"

PongBall::PongBall()
{
}

PongBall::~PongBall()
{
}

void PongBall::setWindow(sf::RenderWindow* handle)
{
	window = handle;
}

float PongBall::getDiameter()
{
	return getSize().x;
}

void PongBall::update(float dt)
{
	if (getPosition().x + getDiameter() > window->getSize().x)
	{
		setPosition(window->getSize().x / 2, window->getSize().y / 2);
	}
	else if (getPosition().x < 0)
	{
		setPosition(window->getSize().x/2, window->getSize().y / 2);
	}
	if (getPosition().y + getDiameter() > window->getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getDiameter());
		velocity.y = -velocity.y;
	}
	else if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity.y = -velocity.y;
	}

	setPosition(getPosition() + dt * velocity);

	setCollisionBox(sf::FloatRect(getPosition(),getSize()));
}
