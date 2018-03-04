#include "bat.hpp"

const float Bat::batSpeed = 1000.0f;

Bat::Bat() : batShape(sf::Vector2<float>(60.0f, 10.0f)), position(0,780) {
	
	batShape.setOutlineThickness(2.0f);
	batShape.setOutlineColor(sf::Color(255, 255, 255, 255));
	batShape.setFillColor(sf::Color(200, 200, 200, 255));
	batShape.setPosition(position);
}

Bat::~Bat() {}

sf::Vector2<float> Bat::getPosition() { return position; }

sf::RectangleShape Bat::getShape() { return batShape; }

void Bat::moveLeft(float timeScale) { position.x -= batSpeed*timeScale; }

void Bat::moveRight(float timeScale) { position.x += batSpeed*timeScale; }

void Bat::update() { batShape.setPosition(position); }