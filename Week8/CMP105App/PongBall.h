#pragma once
#include "Framework/GameObject.h"
class PongBall :
public GameObject
{
	public:
		PongBall();
		~PongBall();

		void setWindow(sf::RenderWindow*);
		float getDiameter();
		void update(float) override;


	private:
		sf::RenderWindow* window;
};

