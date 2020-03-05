#include "PongPaddle.h"
#define speed 225.0f

PongPaddle::PongPaddle()
{

}

PongPaddle::~PongPaddle()
{
}

void PongPaddle::update(float dt)
{
	setCollisionBox(sf::FloatRect(getPosition(), getSize()));
	if (Collision::checkBoundingBox(this,ball))
	{
		ball->setVelocity(-ball->getVelocity().x,ball->getVelocity().y);
	}
}

void PongPaddle::handleInput(float dt)
{
	if (player)
	{
		if (input->isKeyDown(sf::Keyboard::W)) { setPosition(getPosition() + sf::Vector2f(0,-speed) * dt); }
		if (input->isKeyDown(sf::Keyboard::S)) { setPosition(getPosition() + sf::Vector2f(0, speed) * dt); }
	}
	else
	{
		if (input->isMouseLDown())
		{
			setPosition(getPosition() + (speed * Vector::normalise(sf::Vector2f(0, input->getMouseY() - getPosition().y))) * dt);
		}
	}
}

void PongPaddle::setPlayer(bool isP1)
{
	player = isP1;
}

void PongPaddle::setPong(PongBall* pong)
{
	ball = pong;
}
