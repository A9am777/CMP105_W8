#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include "PongBall.h"
#include "Framework/Collision.h"
class PongPaddle :
public GameObject
{
	public:
		PongPaddle();
		~PongPaddle();

		void update(float) override;
		void handleInput(float) override;

		void setPlayer(bool);
		void setPong(PongBall*);

	private:
		bool player;
		PongBall* ball;
};

