#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	tex.loadFromFile("gfx/Beach_Ball.png");
	ball1.setTexture(&tex);
	ball1.setPosition(sf::Vector2f(15.0f, 45.0f));
	ball1.setVelocity(sf::Vector2f(20,0));
	ball1.setSize(sf::Vector2f(50,50));

	ball2 = ball1;
	
	ball1.setPartner(&ball2);
	ball2.setPartner(&ball1);

	ball1.setPosition(sf::Vector2f(350.0f, 49.0f));
	ball1.setVelocity(sf::Vector2f(-20, 2));

	pBall.setTexture(&tex);
	pBall.setSize(sf::Vector2f(50, 50));
	pBall.setPosition(sf::Vector2f(window->getSize().x/2,window->getSize().y/2));
	pBall.setVelocity(sf::Vector2f(250,-75));
	pBall.setWindow(window);

	pdd1.setSize(sf::Vector2f(20,75));
	pdd1.setPosition(sf::Vector2f(100,window->getSize().x/2));
	pdd1.setPong(&pBall);
	pdd1.setInput(input);
	pdd1.setPlayer(false);

	pdd2 = pdd1;
	pdd2.setPlayer(true);
	pdd2.setPosition(sf::Vector2f(800, window->getSize().y / 2));

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	pdd1.handleInput(dt);
	pdd2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	//ball1.update(dt);
	//ball2.update(dt);
	pdd1.update(dt);
	pdd2.update(dt);
	pBall.update(dt);
}

#include <iostream>

// Render level
void Level::render()
{
	beginDraw();
	//window->draw(ball1);
	//window->draw(ball2);

	window->draw(pdd1);
	window->draw(pdd2);
	window->draw(pBall);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}