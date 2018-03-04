#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "ball.hpp"
#include "bat.hpp"

class Game : sf::NonCopyable {
	public:
		Game();
		~Game();
		void processEvents(sf::Time);
		void update(sf::Time);
		void render();
		void run();


	private:
		//some are named a bit differently than the outline specifies, for consistency
		Ball mBall;
		Bat mBat;
		int mLives;
		int mScore; 
		sf::Font mFont;
		sf::Sprite mIcon;
		sf::Music mMusic;
		sf::Text mText;
		sf::RenderWindow mWindow;
		static const sf::Time TimePerFrame;
		static const float mWindowHeight;
		static const float mWindowWidth;
};