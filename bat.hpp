#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

class Bat {
	public:
		Bat();
		~Bat();
		sf::Vector2<float> getPosition();
		sf::RectangleShape getShape();
		void moveLeft();
		void moveRight();
		void update();

	private:
		sf::RectangleShape batShape;
		static const float batSpeed;
		sf::Vector2<float> position;
};