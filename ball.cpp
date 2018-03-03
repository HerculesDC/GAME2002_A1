#include "ball.hpp"

float Ball::xVelocity = 1.0f;
float Ball::yVelocity = 1.0f;

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

void Ball::hitBottom() { position = sf::Vector2<float>(640, 0); }

void Ball::reboundBatOrTop() { yVelocity *= -1; }

void Ball::reboundSides() { xVelocity *= -1; }

void Ball::update() { 
	position += sf::Vector2<float>(xVelocity, yVelocity);
	ballShape.setPosition(position);
}