#include "ball.hpp"

float Ball::xVelocity = 100.0f;
float Ball::yVelocity = 100.0f;

Ball::Ball() : ballShape(10.0f, 4), position(640, 0) { 
	
	ballShape.setOutlineThickness(2.0f);
	ballShape.setOutlineColor(sf::Color(0, 0, 127, 255));
	ballShape.setFillColor(sf::Color(255, 0, 255, 255));	
	ballShape.setPosition(position);
}

Ball::~Ball() { }

sf::Vector2<float> Ball::getPosition() { return position; }

sf::CircleShape Ball::getShape(){ return ballShape; }

float Ball::getXVelocity() { return xVelocity; }

float Ball::getYVelocity() { return yVelocity; }

void Ball::hitBottom() { position.y -= 799.0f; }

void Ball::reboundBatOrTop() { yVelocity *= -1; }

void Ball::reboundSides() { xVelocity *= -1; }

void Ball::update(float timeScale) { 
	position += timeScale * sf::Vector2<float>(xVelocity, yVelocity);
	ballShape.setPosition(position);
}