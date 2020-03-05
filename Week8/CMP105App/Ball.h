#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class Ball :
public GameObject
{
	public:
		Ball();
		~Ball();

		void setPartner(Ball*);
		void update(float) override;
	private:
		Ball* partner;
};

