#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

class Ball {
	public:
		Ball();
		~Ball();
		sf::Vector2<float> getPosition();
		sf::CircleShape getShape();
		float getXVelocity();
		float getYVelocity();
		void hitBottom();
		void reboundBatOrTop();
		void reboundSides();
		void update();
		
	private:
		sf::CircleShape ballShape;
		sf::Vector2<float> position;
		static float xVelocity;
		static float yVelocity;
};